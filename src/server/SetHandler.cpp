#include "SetHandler.hpp"
#include <stdexcept>

CommandName SetHandler::getCommandName() const {
	return CommandName::SET;
}

std::string SetHandler::executeCommand(const Command& command, IStorage& storage) {
	if (command.commandName() != CommandName::SET) {
		throw std::runtime_error("Impossible: SetHandler try to execute not set");
	}

	if (command.value().has_value()) {
		auto value = command.value().value();
		storage.set(command.key(), value);
		return "OK";
	} else {
		throw std::runtime_error(""); //TODO think about custom exception
		// Exception like was got invalid command (isn't valid situation)
	}
}
