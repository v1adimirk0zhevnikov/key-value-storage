#ifndef INTERFACE_COMMAND_HANDLER_HPP
#define INTERFACE_COMMAND_HANDLER_HPP
#include "Command.hpp"
#include "IStorage.hpp"

class ICommandHandler {
public:
	virtual ~ICommandHandler() = default;
	virtual CommandName getCommandName() const = 0;
	virtual std::string executeCommand(const Command& command, IStorage& storage) = 0;	
};

#endif
