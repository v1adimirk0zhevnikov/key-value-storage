#include "DelHandler.hpp"
#include "StorageException.hpp"
#include <stdexcept>

CommandName DelHandler::getCommandName() const {
	return CommandName::DEL;
}

std::string DelHandler::executeCommand(const Command& command, IStorage& storage) {
	if (command.commandName() != CommandName::DEL) {
		throw std::runtime_error(""); // TODO: custom exception
	}

	const Key& key = command.key();

	try{
		storage.del(key);
		return "DELETED SUCCESFUL";
	} catch (const StorageException&) {
		return "NOT FOUND KEY";
	}
};
