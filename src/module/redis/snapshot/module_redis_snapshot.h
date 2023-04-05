#ifndef CACHEGRAND_MODULE_REDIS_SNAPSHOT_H
#define CACHEGRAND_MODULE_REDIS_SNAPSHOT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "misc.h"

#define MODULE_REDIS_SNAPSHOT_RDB_VERSION 11

// List of possible value types in RDB snapshots
enum module_redis_snapshot_value_type {
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STRING = 0x00,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_LIST = 0x01,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_SET = 0x02,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_ZSET = 0x03,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_HASH = 0x04,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_ZSET_2 = 0x05,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_MODULE_PRE_GA = 0x06,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_MODULE_2 = 0x07,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_HASH_ZIPMAP = 0x09,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_LIST_ZIPLIST = 0x0A,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_SET_INTSET = 0x0B,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_ZSET_ZIPLIST = 0x0C,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_HASH_ZIPLIST = 0x0D,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_LIST_QUICKLIST = 0x0E,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STREAM_LISTPACKS = 0x0F,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_HASH_LISTPACK = 0x10,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_ZSET_LISTPACK = 0x11,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_LIST_QUICKLIST_2 = 0x12,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STREAM_LISTPACKS_2 = 0x13,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_SET_LISTPACK = 0x14,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STREAM_LISTPACKS_3 = 0x15,
    MODULE_REDIS_SNAPSHOT_VALUE_TYPE_MAX,
};
typedef enum module_redis_snapshot_value_type module_snapshot_value_type_t;

#define MODULE_REDIS_SNAPSHOT_VALUES_TYPES MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STRING, MODULE_REDIS_SNAPSHOT_VALUE_TYPE_LIST, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_SET, MODULE_REDIS_SNAPSHOT_VALUE_TYPE_ZSET, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_HASH, MODULE_REDIS_SNAPSHOT_VALUE_TYPE_ZSET_2, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_MODULE_PRE_GA, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_MODULE_2, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_HASH_ZIPMAP, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_LIST_ZIPLIST, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_SET_INTSET, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_ZSET_ZIPLIST, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_HASH_ZIPLIST, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_LIST_QUICKLIST, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STREAM_LISTPACKS, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_HASH_LISTPACK, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_ZSET_LISTPACK, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_LIST_QUICKLIST_2, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STREAM_LISTPACKS_2, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_SET_LISTPACK, \
                                         MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STREAM_LISTPACKS_3

#define MODULE_REDIS_SNAPSHOT_VALUES_TYPES_COUNT (sizeof(module_snapshot_rdb_values_types) / sizeof(uint32_t))

#define MODULE_REDIS_SNAPSHOT_VALUES_TYPES_MIN    (((int[]){ MODULE_REDIS_SNAPSHOT_VALUES_TYPES })[0])
#define MODULE_REDIS_SNAPSHOT_VALUES_TYPES_MAX    (((int[]){ MODULE_REDIS_SNAPSHOT_VALUES_TYPES })[MODULE_REDIS_SNAPSHOT_VALUES_TYPES_COUNT - 1])

static const uint32_t module_snapshot_rdb_values_types[] = { MODULE_REDIS_SNAPSHOT_VALUES_TYPES };

// List of supported value types in RDB snapshots
#define MODULE_REDIS_SNAPSHOT_VALUES_TYPES_SUPPORTED MODULE_REDIS_SNAPSHOT_VALUE_TYPE_STRING

#define MODULE_REDIS_SNAPSHOT_VALUES_TYPES_SUPPORTED_COUNT (sizeof(module_redis_snapshot_rdb_values_types_supported) / sizeof(uint32_t))

#define MODULE_REDIS_SNAPSHOT_VALUES_TYPES_SUPPORTED_MIN    (((int[]){ MODULE_REDIS_SNAPSHOT_VALUES_TYPES_SUPPORTED })[0])
#define MODULE_REDIS_SNAPSHOT_VALUES_TYPES_SUPPORTED_MAX    (((int[]){ MODULE_REDIS_SNAPSHOT_VALUES_TYPES_SUPPORTED })[MODULE_REDIS_SNAPSHOT_VALUES_TYPES_SUPPORTED_COUNT - 1])

static const uint32_t module_redis_snapshot_rdb_values_types_supported[] = {MODULE_REDIS_SNAPSHOT_VALUES_TYPES_SUPPORTED };

// List of possible opcodes in RDB snapshots
enum module_redis_snapshot_opcode {
    MODULE_REDIS_SNAPSHOT_OPCODE_FUNCTION = 0xF5,
    MODULE_REDIS_SNAPSHOT_OPCODE_FUNCTION_PRE_7 = 0xF6,
    MODULE_REDIS_SNAPSHOT_OPCODE_MODULE_AUX = 0xF7,
    MODULE_REDIS_SNAPSHOT_OPCODE_LRU_IDLE = 0xF8,
    MODULE_REDIS_SNAPSHOT_OPCODE_LFU_FREQUENCY = 0xF9,
    MODULE_REDIS_SNAPSHOT_OPCODE_AUX = 0xFA,
    MODULE_REDIS_SNAPSHOT_OPCODE_RESIZE_DB = 0xFB,
    MODULE_REDIS_SNAPSHOT_OPCODE_EXPIRE_TIME_MS = 0xFC,
    MODULE_REDIS_SNAPSHOT_OPCODE_EXPIRE_TIME = 0xFD,
    MODULE_REDIS_SNAPSHOT_OPCODE_DB_NUMBER = 0xFE,
    MODULE_REDIS_SNAPSHOT_OPCODE_EOF = 0xFF,
};
typedef enum module_redis_snapshot_opcode module_redis_snapshot_opcode_t;

#define MODULE_REDIS_SNAPSHOT_OPCODES MODULE_REDIS_SNAPSHOT_OPCODE_FUNCTION, MODULE_REDIS_SNAPSHOT_OPCODE_FUNCTION_PRE_7, \
                                     MODULE_REDIS_SNAPSHOT_OPCODE_MODULE_AUX, MODULE_REDIS_SNAPSHOT_OPCODE_LRU_IDLE, \
                                     MODULE_REDIS_SNAPSHOT_OPCODE_LFU_FREQUENCY, MODULE_REDIS_SNAPSHOT_OPCODE_AUX, \
                                     MODULE_REDIS_SNAPSHOT_OPCODE_RESIZE_DB, MODULE_REDIS_SNAPSHOT_OPCODE_EXPIRE_TIME_MS, \
                                     MODULE_REDIS_SNAPSHOT_OPCODE_EXPIRE_TIME, MODULE_REDIS_SNAPSHOT_OPCODE_DB_NUMBER, \
                                     MODULE_REDIS_SNAPSHOT_OPCODE_EOF

#define MODULE_REDIS_SNAPSHOT_OPCODES_COUNT (sizeof(module_redis_snapshot_opcodes) / sizeof(uint32_t))

#define MODULE_REDIS_SNAPSHOT_OPCODES_MIN    (((int[]){ MODULE_REDIS_SNAPSHOT_OPCODES })[0])
#define MODULE_REDIS_SNAPSHOT_OPCODES_MAX    (((int[]){ MODULE_REDIS_SNAPSHOT_OPCODES })[MODULE_REDIS_SNAPSHOT_OPCODES_COUNT - 1])

static const uint32_t module_redis_snapshot_opcodes[] = { MODULE_REDIS_SNAPSHOT_OPCODES };

struct module_redis_snapshot_header {
    uint8_t version;
};
typedef struct module_redis_snapshot_header module_redis_snapshot_header_t;

bool module_redis_snapshot_is_value_type_valid(
        module_snapshot_value_type_t value_type);

bool module_redis_snapshot_is_value_type_supported(
        module_snapshot_value_type_t value_type);

#ifdef __cplusplus
}
#endif

#endif //CACHEGRAND_MODULE_REDIS_SNAPSHOT_H
