#ifndef AUTOREGISTER_HPP
#define AUTOREGISTER_HPP

#include "CommandRegistrar.hpp"
#include "Command.hpp"



namespace RedisCommand {

template<class T>
    class AutoRegister {
        public:
            explicit AutoRegister(const std::string& name) {
                RedisCommand::CommandRegistrar::register_command(name, &T::get_instance());
            }
    };
}

#define REGISTER_COMMAND(CommandType, CommandName) \
    inline RedisCommand::AutoRegister<CommandType> register_##CommandType(CommandName);
#endif //AUTOREGISTER_HPP
