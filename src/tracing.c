/*
 * Copyright (c) 2020 Olaf Landsiedel
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/types.h>
#include <stddef.h>
#include <sys/printk.h>
#include <sys/util.h>
#include <string.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <kernel.h>

#include "exposure-notification.h"
#include "tracing.h"
#include "record_storage.h"

#include "utility/util.h"

#define COVID_ENS (0xFD6F)

typedef ENIntervalIdentifier ENIntervalIdentifier;





typedef struct period{
    ENPeriodKey periodKey;
    ENIntervalNumber periodInterval;
} __packed period_t;


typedef struct covid_adv_svd
{
	uint16_t ens;
	ENIntervalIdentifier rolling_proximity_identifier;
	associated_encrypted_metadata_t associated_encrypted_metadata;
} __packed covid_adv_svd_t;

const static bt_metadata_t bt_metadata = {
	.version = 0b00100000,
	.tx_power = 0, //TODO set to actual transmit power
	.rsv1 = 0,
	.rsv2 = 0,
};

static covid_adv_svd_t covid_adv_svd = {
	.ens = COVID_ENS,
	//do not initialiuze the rest of the packet, will write this later
};

static struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0x6f, 0xfd), //0xFD6F Exposure Notification Service
	BT_DATA(BT_DATA_SVC_DATA16, &covid_adv_svd, sizeof(covid_adv_svd_t))};

static struct k_mutex key_change_lock;

static void scan_cb(const bt_addr_le_t *addr, int8_t rssi, uint8_t adv_type, struct net_buf_simple *buf)
{
	if (adv_type == 3)
	{
		uint8_t len = 0;

		while (buf->len > 1)
		{
			uint8_t type;

			len = net_buf_simple_pull_u8(buf);
			if (!len)
			{
				break;
			}
			/* Check if field length is correct */
			if (len > buf->len || buf->len < 1)
			{
				break;
			}
			type = net_buf_simple_pull_u8(buf);
			if (type == BT_DATA_SVC_DATA16 && len == sizeof(covid_adv_svd_t) + 1)
			{
				covid_adv_svd_t *rx_adv = (covid_adv_svd_t *)buf->data;
				if (rx_adv->ens == COVID_ENS)
				{
                    printk("Attempting to store record...\n");
                    record_t record;
                    uint32_t timestamp = time_get_unix_seconds();
                    memcpy(&record.rssi, &rssi, sizeof(record.rssi));
                    memcpy(&record.associated_encrypted_metadata, &rx_adv->associated_encrypted_metadata, sizeof(record.associated_encrypted_metadata));
                    memcpy(&record.rolling_proximity_identifier, &rx_adv->rolling_proximity_identifier, sizeof(record.rolling_proximity_identifier));
                    memcpy(&record.timestamp, &timestamp, sizeof(record.timestamp));
                    int rc = add_record(&record);
                    printk("Record stored (err %d)\n", rc);
				}
			}
			net_buf_simple_pull(buf, len - 1); //consume the rest, note we already consumed one byte via net_buf_simple_pull_u8(buf)
		}
	}
}

#define NUM_PERIOD_KEYS (14)
static period_t periods[NUM_PERIOD_KEYS];

static int current_period_index = 0;
static ENIntervalNumber currentInterval;
static unsigned int period_cnt = 0;

static ENPeriodMetadataEncryptionKey periodMetadataEncryptionKey;
static ENIntervalIdentifier intervalIdentifier;
static associated_encrypted_metadata_t encryptedMetadata;

static bool init = 1;
static bool infected = 0;

static void test_against_fixtures(void)
{
	// First define base values
	ENIntervalNumber intervalNumber = 2642976;
	ENPeriodKey periodKey = {.b = {0x75, 0xc7, 0x34, 0xc6, 0xdd, 0x1a, 0x78, 0x2d, 0xe7, 0xa9, 0x65, 0xda, 0x5e, 0xb9, 0x31, 0x25}};
	unsigned char metadata[4] = {0x40, 0x08, 0x00, 0x00};

	// define the expected values
	ENPeriodIdentifierKey expectedPIK = {.b = {0x18, 0x5a, 0xd9, 0x1d, 0xb6, 0x9e, 0xc7, 0xdd, 0x04, 0x89, 0x60, 0xf1, 0xf3, 0xba, 0x61, 0x75}};
	ENPeriodMetadataEncryptionKey expectedPMEK = {.b = {0xd5, 0x7c, 0x46, 0xaf, 0x7a, 0x1d, 0x83, 0x96, 0x5b, 0x9b, 0xed, 0x8b, 0xd1, 0x52, 0x93, 0x6a}};

	ENIntervalIdentifier expectedIntervalIdentifier = {.b = {0x8b, 0xe6, 0xcd, 0x37, 0x1c, 0x5c, 0x89, 0x16, 0x04, 0xbf, 0xbe, 0x49, 0xdf, 0x84, 0x50, 0x96}};
	unsigned char expectedEncryptedMetadata[4] = {0x72, 0x03, 0x38, 0x74};

	ENPeriodIdentifierKey pik;
	en_derive_period_identifier_key(&pik, &periodKey);

	printk("expectedPIK: ");
	print_key(&expectedPIK);
	printk(", ");
	printk("actualPIK: ");
	print_key(&pik);
	printk(", ");

	ENIntervalIdentifier intervalIdentifier;
	en_derive_interval_identifier(&intervalIdentifier, &pik, intervalNumber);

	printk("expectedRPI: ");
	print_key(&expectedIntervalIdentifier);
	printk(", ");
	printk("actualRPI: ");
	print_key(&intervalIdentifier);
	printk(", ");

	/*ENPeriodMetadataEncryptionKey pmek;
    en_derive_period_metadata_encryption_key(&pmek, &periodKey);
    TEST_ASSERT_EQUAL_KEY(expectedPMEK, pmek);

    unsigned char encryptedMetadata[sizeof(metadata)] = {0};
    en_encrypt_interval_metadata(&pmek, &intervalIdentifier, metadata, encryptedMetadata, sizeof(metadata));
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expectedEncryptedMetadata, encryptedMetadata, sizeof(expectedEncryptedMetadata));*/
}

static void new_period_key(time_t currentTime)
{	
	#ifndef NATIVE_POSIX
	printk("\n----------------------------------------\n\n");
	printk("\n----------------------------------------\n\n");
	printk("*** New Period\n");
	current_period_index = period_cnt % NUM_PERIOD_KEYS;
	periods[current_period_index].periodInterval = en_get_interval_number_at_period_start(currentTime);
	printk("periodInterval %u\n", periods[current_period_index].periodInterval);
	en_generate_period_key(&periods[current_period_index].periodKey);
	period_cnt++;
	#endif
}

//To be called when new keys are needed
static void check_keys(struct k_work *work)
{

	// we check the current time to know if we actually need to regenerate anything
	// TODO: Use real unix timestamp!: currentTime = time(NULL);
	uint32_t currentTime = time_get_unix_seconds();
	ENIntervalNumber newInterval = en_get_interval_number(currentTime);
	if (currentInterval != newInterval || init)
	{
		currentInterval = newInterval;
		bool newPeriod = ((currentInterval - periods[current_period_index].periodInterval) >= EN_TEK_ROLLING_PERIOD);
		// we check if we need to generate new keys
		if (newPeriod || init)
		{
			new_period_key(currentTime);
		}

		// we now generate the new interval identifier and re-encrypt the metadata
		// TODO: The period identifier key does not need to be derived everytime!
		ENPeriodIdentifierKey pik;
		en_derive_period_identifier_key(&pik, &periods[current_period_index].periodKey);
		en_derive_interval_identifier(&intervalIdentifier, &pik, currentInterval);
		
		en_derive_period_metadata_encryption_key(&periodMetadataEncryptionKey, &periods[current_period_index].periodKey);
		en_encrypt_interval_metadata(&periodMetadataEncryptionKey, &intervalIdentifier, (unsigned char*)&bt_metadata, (unsigned char*)&encryptedMetadata, sizeof(associated_encrypted_metadata_t));
		

		// broadcast intervalIdentifier plus encryptedMetada according to specs
		//printk("\n----------------------------------------\n\n");
		printk("Time: %u, ", currentTime);
		printk("Interval: %u, ", currentInterval);
		printk("TEK: ");
		print_rpi((ENIntervalIdentifier *)&periods[current_period_index].periodKey);
		printk(", ");
		printk("RPI: ");
		print_rpi((ENIntervalIdentifier *)&intervalIdentifier);
		printk(", ");
		printk("AEM: ");
		print_aem(&encryptedMetadata);
		printk("\n");
		
		// lock, so we can be sure to only advertise correct packages 
		k_mutex_lock(&key_change_lock, K_FOREVER);
		memcpy(&covid_adv_svd.rolling_proximity_identifier, &intervalIdentifier, sizeof(ENIntervalIdentifier));
		memcpy(&covid_adv_svd.associated_encrypted_metadata, &encryptedMetadata, sizeof(associated_encrypted_metadata_t));
		k_mutex_unlock(&key_change_lock);

		init = 0;
	}
}

K_WORK_DEFINE(my_work, check_keys);

static void my_timer_handler(struct k_timer *dummy)
{
	k_work_submit(&my_work);
}

K_TIMER_DEFINE(my_timer, my_timer_handler, NULL);

static const struct bt_le_scan_param scan_param = {
	.type = BT_HCI_LE_SCAN_PASSIVE,
	.options = BT_LE_SCAN_OPT_FILTER_DUPLICATE,
	.interval = 0x0010, //Scan Interval (N * 0.625 ms), TODO: set to correct interval
	.window = 0x0010,	//Scan Window (N * 0.625 ms), TODO: set to correct interval
};

#define KEY_CHECK_INTERVAL (K_MSEC(EN_INTERVAL_LENGTH * 1000 / 10))

int tracing_init()
{

#if COVID_MEASURE_PERFORMANCE
	measure_performance();
#endif

	// TODO: Use real unix timestamp!: currentTime = time(NULL);
	init = 1;
	period_cnt = 0;
	infected = 0;

	test_against_fixtures();

	check_keys(NULL);

	int err = 0;
	#if CONFIG_BT
	err = bt_le_scan_start(&scan_param, scan_cb);
	#endif
	if (err)
	{
		printk("Starting scanning failed (err %d)\n", err);
		return err;
	}

	k_mutex_init(&key_change_lock);

	k_timer_start(&my_timer, KEY_CHECK_INTERVAL, KEY_CHECK_INTERVAL);
	return 0;
}

int tracing_run()
{
	//printk("covid start\n");

	int err = 0;
	#if CONFIG_BT
	
	k_mutex_lock(&key_change_lock, K_FOREVER);
	err = bt_le_adv_start(BT_LE_ADV_NCONN, ad, ARRAY_SIZE(ad), NULL, 0);
	#endif

	if (err)
	{
		printk("Advertising failed to start (err %d)\n", err);
		return err;
	}

	k_sleep(K_SECONDS(10));

	#if CONFIG_BT
	err = bt_le_adv_stop();
	#endif
	k_mutex_unlock(&key_change_lock);

	if (err)
	{
		printk("Advertising failed to stop (err %d)\n", err);
		return err;
	}
	//printk("covid end\n");
	return 0;
}

bool get_infection()
{
	return infected;
}

void set_infection(bool _infected)
{
	infected = _infected;
}

unsigned int get_period_cnt_if_infected()
{
	if (!infected)
	{
		return 0;
	}
	return period_cnt;
}

period_t *get_period_if_infected(unsigned int id, size_t *size)
{
	if (!infected || id >= NUM_PERIOD_KEYS || id >= period_cnt)
	{
		*size = 0;
		return NULL;
	}
	*size = sizeof(period_t);
	return &periods[id];
}