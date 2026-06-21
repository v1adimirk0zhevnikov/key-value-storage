#include "GetHandler.hpp"
#include <stdexcept>

CommandName GetHandler::getCommandName() const {
	return CommandName::GET;
}

std::string GetHandler::executeCommand(const Command& command, IStorage& storage) {
	if (command.commandName() != CommandName::GET) {
		throw std::runtime_error(""); // TODO: CASTOM exception in each handler?
	}

	const Key& key = command.key();
	auto result = storage.get(key);
	        
	if (result.has_value()) {
		return result.value().value();
	} else {
	    return "NOT FOUND";
	}
}

