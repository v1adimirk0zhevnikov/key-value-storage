#ifndef COMMAND_DISTPATCHER_CLASS_HPP
#define COMMAND_DISTPATCHER_CLASS_HPP
#include "Command.hpp"
#include "ICommandHandler.hpp"

#include <unordered_map>
#include <string>
#include <memory>

class CommandDispatcher final {
private:
	std::unordered_map<CommandName, std::unique_ptr<ICommandHandler>> m_handlers;
public:
	void addHandler(std::unique_ptr<ICommandHandler> handler);

	std::string execute(const Command& command, IStorage& storage);
};


#endif
