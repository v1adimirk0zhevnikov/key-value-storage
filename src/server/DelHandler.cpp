#include "DelHandler.hpp"
#include "StorageException.hpp"
#include <stdexcept>

CommandName DelHandler::getCommandName() const {
	return CommandName::DEL;
}

std::string DelHandler::executeCommand(const Command& command, IStorage& storage) {
	const Key& key = command.key();

	try{
		storage.del(key);
		return "DELETED SUCCESFUL";
	} catch (const StorageException&) {
		return "NOT FOUND";
	} catch (const std::runtime_error&) {
		return "FAILED TO DELETE";
	}
};
