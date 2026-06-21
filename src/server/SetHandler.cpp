#include "SetHandler.hpp"
#include "StorageException.hpp"
#include <stdexcept>

CommandName SetHandler::getCommandName() const {
	return CommandName::SET;
}

std::string SetHandler::executeCommand(const Command& command, IStorage& storage) {
	if (command.commandName() != CommandName::SET) {
		throw std::runtime_error("Impossible: SetHandler try to execute not set");
	}
	
	if (command.value().has_value()) {
		try{
			auto value = command.value().value();
			storage.set(command.key(), value);
			return "OK";
		} catch (const StorageException& e) {
			return e.what();
		}
	} else {
		throw std::invalid_argument("Incorrect command");
	}
}
