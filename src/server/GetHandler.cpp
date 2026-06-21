#include "GetHandler.hpp"
#include "StorageException.hpp"
#include <stdexcept>

CommandName GetHandler::getCommandName() const {
	return CommandName::GET;
}

std::string GetHandler::executeCommand(const Command& command, IStorage& storage) {
	const Key& key = command.key();
	try {
		auto result = storage.get(key);
	        
		if (result.has_value()) {
			return result.value().value();
		} else {
		    return "NOT FOUND";
		}
	} catch (const StorageException& e) {
		return e.what();
	}
}

