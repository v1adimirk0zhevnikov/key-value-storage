#include "CommandDispatcher.hpp"


void CommandDispatcher::addHandler(std::unique_ptr<ICommandHandler> handler) {
	m_handlers.insert_or_assign(handler->getCommandName(), std::move(handler));
}


std::string CommandDispatcher::execute(const Command& command, IStorage& storage) {
	auto it = m_handlers.find(command.commandName());

	if (it == m_handlers.end()) {
		return "ERROR: cannot execute unknown command";
	}

	return it->second->executeCommand(command, storage);
}
