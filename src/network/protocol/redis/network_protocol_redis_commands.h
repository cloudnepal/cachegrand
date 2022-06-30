#ifndef CACHEGRAND_NETWORK_PROTOCOL_REDIS_COMMANDS_H
#define CACHEGRAND_NETWORK_PROTOCOL_REDIS_COMMANDS_H

#ifdef __cplusplus
extern "C" {
#endif

// HELLO command
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_BEGIN(hello);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_FULL(hello);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_END(hello);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_FREE(hello);

// SHUTDOWN
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_BEGIN(shutdown);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_END(shutdown);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_FREE(shutdown);

// QUIT
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_BEGIN(quit);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_END(quit);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_FREE(quit);

// PING
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_BEGIN(ping);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_END(ping);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_FREE(ping);

// SET
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_BEGIN(set);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_REQUIRE_STREAM(set);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_BEGIN(set);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_DATA(set);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_END(set);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_FULL(set);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_END(set);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_FREE(set);

// GET
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_BEGIN(get);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_REQUIRE_STREAM(get);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_BEGIN(get);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_DATA(get);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_END(get);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_FULL(get);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_END(get);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_FREE(get);

// DEL
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_BEGIN(del);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_REQUIRE_STREAM(del);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_BEGIN(del);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_DATA(del);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_STREAM_END(del);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_ARGUMENT_FULL(del);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_END(del);
NETWORK_PROTOCOL_REDIS_COMMAND_FUNCPTR_COMMAND_FREE(del);

#ifdef __cplusplus
}
#endif

#endif //CACHEGRAND_NETWORK_PROTOCOL_REDIS_COMMANDS_H
