/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: export.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "export.pb-c.h"
void   temporary_exposure_key_export__init
                     (TemporaryExposureKeyExport         *message)
{
  static const TemporaryExposureKeyExport init_value = TEMPORARY_EXPOSURE_KEY_EXPORT__INIT;
  *message = init_value;
}
size_t temporary_exposure_key_export__get_packed_size
                     (const TemporaryExposureKeyExport *message)
{
  assert(message->base.descriptor == &temporary_exposure_key_export__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t temporary_exposure_key_export__pack
                     (const TemporaryExposureKeyExport *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &temporary_exposure_key_export__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t temporary_exposure_key_export__pack_to_buffer
                     (const TemporaryExposureKeyExport *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &temporary_exposure_key_export__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
TemporaryExposureKeyExport *
       temporary_exposure_key_export__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (TemporaryExposureKeyExport *)
     protobuf_c_message_unpack (&temporary_exposure_key_export__descriptor,
                                allocator, len, data);
}
void   temporary_exposure_key_export__free_unpacked
                     (TemporaryExposureKeyExport *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &temporary_exposure_key_export__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   signature_info__init
                     (SignatureInfo         *message)
{
  static const SignatureInfo init_value = SIGNATURE_INFO__INIT;
  *message = init_value;
}
size_t signature_info__get_packed_size
                     (const SignatureInfo *message)
{
  assert(message->base.descriptor == &signature_info__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t signature_info__pack
                     (const SignatureInfo *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &signature_info__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t signature_info__pack_to_buffer
                     (const SignatureInfo *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &signature_info__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
SignatureInfo *
       signature_info__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (SignatureInfo *)
     protobuf_c_message_unpack (&signature_info__descriptor,
                                allocator, len, data);
}
void   signature_info__free_unpacked
                     (SignatureInfo *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &signature_info__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   temporary_exposure_key__init
                     (TemporaryExposureKey         *message)
{
  static const TemporaryExposureKey init_value = TEMPORARY_EXPOSURE_KEY__INIT;
  *message = init_value;
}
size_t temporary_exposure_key__get_packed_size
                     (const TemporaryExposureKey *message)
{
  assert(message->base.descriptor == &temporary_exposure_key__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t temporary_exposure_key__pack
                     (const TemporaryExposureKey *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &temporary_exposure_key__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t temporary_exposure_key__pack_to_buffer
                     (const TemporaryExposureKey *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &temporary_exposure_key__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
TemporaryExposureKey *
       temporary_exposure_key__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (TemporaryExposureKey *)
     protobuf_c_message_unpack (&temporary_exposure_key__descriptor,
                                allocator, len, data);
}
void   temporary_exposure_key__free_unpacked
                     (TemporaryExposureKey *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &temporary_exposure_key__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   teksignature_list__init
                     (TEKSignatureList         *message)
{
  static const TEKSignatureList init_value = TEKSIGNATURE_LIST__INIT;
  *message = init_value;
}
size_t teksignature_list__get_packed_size
                     (const TEKSignatureList *message)
{
  assert(message->base.descriptor == &teksignature_list__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t teksignature_list__pack
                     (const TEKSignatureList *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &teksignature_list__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t teksignature_list__pack_to_buffer
                     (const TEKSignatureList *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &teksignature_list__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
TEKSignatureList *
       teksignature_list__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (TEKSignatureList *)
     protobuf_c_message_unpack (&teksignature_list__descriptor,
                                allocator, len, data);
}
void   teksignature_list__free_unpacked
                     (TEKSignatureList *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &teksignature_list__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   teksignature__init
                     (TEKSignature         *message)
{
  static const TEKSignature init_value = TEKSIGNATURE__INIT;
  *message = init_value;
}
size_t teksignature__get_packed_size
                     (const TEKSignature *message)
{
  assert(message->base.descriptor == &teksignature__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t teksignature__pack
                     (const TEKSignature *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &teksignature__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t teksignature__pack_to_buffer
                     (const TEKSignature *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &teksignature__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
TEKSignature *
       teksignature__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (TEKSignature *)
     protobuf_c_message_unpack (&teksignature__descriptor,
                                allocator, len, data);
}
void   teksignature__free_unpacked
                     (TEKSignature *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &teksignature__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor temporary_exposure_key_export__field_descriptors[8] =
{
  {
    "start_timestamp",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_FIXED64,
    offsetof(TemporaryExposureKeyExport, has_start_timestamp),
    offsetof(TemporaryExposureKeyExport, start_timestamp),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "end_timestamp",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_FIXED64,
    offsetof(TemporaryExposureKeyExport, has_end_timestamp),
    offsetof(TemporaryExposureKeyExport, end_timestamp),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "region",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(TemporaryExposureKeyExport, region),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "batch_num",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(TemporaryExposureKeyExport, has_batch_num),
    offsetof(TemporaryExposureKeyExport, batch_num),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "batch_size",
    5,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(TemporaryExposureKeyExport, has_batch_size),
    offsetof(TemporaryExposureKeyExport, batch_size),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "signature_infos",
    6,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(TemporaryExposureKeyExport, n_signature_infos),
    offsetof(TemporaryExposureKeyExport, signature_infos),
    &signature_info__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "keys",
    7,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(TemporaryExposureKeyExport, n_keys),
    offsetof(TemporaryExposureKeyExport, keys),
    &temporary_exposure_key__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "revised_keys",
    8,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(TemporaryExposureKeyExport, n_revised_keys),
    offsetof(TemporaryExposureKeyExport, revised_keys),
    &temporary_exposure_key__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned temporary_exposure_key_export__field_indices_by_name[] = {
  3,   /* field[3] = batch_num */
  4,   /* field[4] = batch_size */
  1,   /* field[1] = end_timestamp */
  6,   /* field[6] = keys */
  2,   /* field[2] = region */
  7,   /* field[7] = revised_keys */
  5,   /* field[5] = signature_infos */
  0,   /* field[0] = start_timestamp */
};
static const ProtobufCIntRange temporary_exposure_key_export__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 8 }
};
const ProtobufCMessageDescriptor temporary_exposure_key_export__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "TemporaryExposureKeyExport",
  "TemporaryExposureKeyExport",
  "TemporaryExposureKeyExport",
  "",
  sizeof(TemporaryExposureKeyExport),
  8,
  temporary_exposure_key_export__field_descriptors,
  temporary_exposure_key_export__field_indices_by_name,
  1,  temporary_exposure_key_export__number_ranges,
  (ProtobufCMessageInit) temporary_exposure_key_export__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor signature_info__field_descriptors[3] =
{
  {
    "verification_key_version",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(SignatureInfo, verification_key_version),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "verification_key_id",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(SignatureInfo, verification_key_id),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "signature_algorithm",
    5,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(SignatureInfo, signature_algorithm),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned signature_info__field_indices_by_name[] = {
  2,   /* field[2] = signature_algorithm */
  1,   /* field[1] = verification_key_id */
  0,   /* field[0] = verification_key_version */
};
static const ProtobufCIntRange signature_info__number_ranges[1 + 1] =
{
  { 3, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor signature_info__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "SignatureInfo",
  "SignatureInfo",
  "SignatureInfo",
  "",
  sizeof(SignatureInfo),
  3,
  signature_info__field_descriptors,
  signature_info__field_indices_by_name,
  1,  signature_info__number_ranges,
  (ProtobufCMessageInit) signature_info__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue temporary_exposure_key__report_type__enum_values_by_number[6] =
{
  { "UNKNOWN", "TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__UNKNOWN", 0 },
  { "CONFIRMED_TEST", "TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__CONFIRMED_TEST", 1 },
  { "CONFIRMED_CLINICAL_DIAGNOSIS", "TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__CONFIRMED_CLINICAL_DIAGNOSIS", 2 },
  { "SELF_REPORT", "TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__SELF_REPORT", 3 },
  { "RECURSIVE", "TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__RECURSIVE", 4 },
  { "REVOKED", "TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__REVOKED", 5 },
};
static const ProtobufCIntRange temporary_exposure_key__report_type__value_ranges[] = {
{0, 0},{0, 6}
};
static const ProtobufCEnumValueIndex temporary_exposure_key__report_type__enum_values_by_name[6] =
{
  { "CONFIRMED_CLINICAL_DIAGNOSIS", 2 },
  { "CONFIRMED_TEST", 1 },
  { "RECURSIVE", 4 },
  { "REVOKED", 5 },
  { "SELF_REPORT", 3 },
  { "UNKNOWN", 0 },
};
const ProtobufCEnumDescriptor temporary_exposure_key__report_type__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "TemporaryExposureKey.ReportType",
  "ReportType",
  "TemporaryExposureKey__ReportType",
  "",
  6,
  temporary_exposure_key__report_type__enum_values_by_number,
  6,
  temporary_exposure_key__report_type__enum_values_by_name,
  1,
  temporary_exposure_key__report_type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const int32_t temporary_exposure_key__rolling_period__default_value = 144;
static const ProtobufCFieldDescriptor temporary_exposure_key__field_descriptors[6] =
{
  {
    "key_data",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(TemporaryExposureKey, has_key_data),
    offsetof(TemporaryExposureKey, key_data),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "transmission_risk_level",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(TemporaryExposureKey, has_transmission_risk_level),
    offsetof(TemporaryExposureKey, transmission_risk_level),
    NULL,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_DEPRECATED,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "rolling_start_interval_number",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(TemporaryExposureKey, has_rolling_start_interval_number),
    offsetof(TemporaryExposureKey, rolling_start_interval_number),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "rolling_period",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(TemporaryExposureKey, has_rolling_period),
    offsetof(TemporaryExposureKey, rolling_period),
    NULL,
    &temporary_exposure_key__rolling_period__default_value,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "report_type",
    5,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_ENUM,
    offsetof(TemporaryExposureKey, has_report_type),
    offsetof(TemporaryExposureKey, report_type),
    &temporary_exposure_key__report_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "days_since_onset_of_symptoms",
    6,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_SINT32,
    offsetof(TemporaryExposureKey, has_days_since_onset_of_symptoms),
    offsetof(TemporaryExposureKey, days_since_onset_of_symptoms),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned temporary_exposure_key__field_indices_by_name[] = {
  5,   /* field[5] = days_since_onset_of_symptoms */
  0,   /* field[0] = key_data */
  4,   /* field[4] = report_type */
  3,   /* field[3] = rolling_period */
  2,   /* field[2] = rolling_start_interval_number */
  1,   /* field[1] = transmission_risk_level */
};
static const ProtobufCIntRange temporary_exposure_key__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 6 }
};
const ProtobufCMessageDescriptor temporary_exposure_key__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "TemporaryExposureKey",
  "TemporaryExposureKey",
  "TemporaryExposureKey",
  "",
  sizeof(TemporaryExposureKey),
  6,
  temporary_exposure_key__field_descriptors,
  temporary_exposure_key__field_indices_by_name,
  1,  temporary_exposure_key__number_ranges,
  (ProtobufCMessageInit) temporary_exposure_key__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor teksignature_list__field_descriptors[1] =
{
  {
    "signatures",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(TEKSignatureList, n_signatures),
    offsetof(TEKSignatureList, signatures),
    &teksignature__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned teksignature_list__field_indices_by_name[] = {
  0,   /* field[0] = signatures */
};
static const ProtobufCIntRange teksignature_list__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor teksignature_list__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "TEKSignatureList",
  "TEKSignatureList",
  "TEKSignatureList",
  "",
  sizeof(TEKSignatureList),
  1,
  teksignature_list__field_descriptors,
  teksignature_list__field_indices_by_name,
  1,  teksignature_list__number_ranges,
  (ProtobufCMessageInit) teksignature_list__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor teksignature__field_descriptors[4] =
{
  {
    "signature_info",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(TEKSignature, signature_info),
    &signature_info__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "batch_num",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(TEKSignature, has_batch_num),
    offsetof(TEKSignature, batch_num),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "batch_size",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(TEKSignature, has_batch_size),
    offsetof(TEKSignature, batch_size),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "signature",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BYTES,
    offsetof(TEKSignature, has_signature),
    offsetof(TEKSignature, signature),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned teksignature__field_indices_by_name[] = {
  1,   /* field[1] = batch_num */
  2,   /* field[2] = batch_size */
  3,   /* field[3] = signature */
  0,   /* field[0] = signature_info */
};
static const ProtobufCIntRange teksignature__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor teksignature__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "TEKSignature",
  "TEKSignature",
  "TEKSignature",
  "",
  sizeof(TEKSignature),
  4,
  teksignature__field_descriptors,
  teksignature__field_indices_by_name,
  1,  teksignature__number_ranges,
  (ProtobufCMessageInit) teksignature__init,
  NULL,NULL,NULL    /* reserved[123] */
};