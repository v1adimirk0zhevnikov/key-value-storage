#include "ParsingUtils.hpp"

namespace parsing{

	std::vector<std::string_view> split(std::string_view line, const char delimeter) {
		auto result = std::vector<std::string_view>();
	
		size_t start = 0;
		size_t end = line.find(delimeter);
		    
		while (end != std::string_view::npos) {
			result.push_back(line.substr(start, end - start));
		    start = end + 1;
		    end = line.find(delimeter, start);
		}
		result.push_back(line.substr(start));
		    
	    return result;
	}
	
	std::string commandToLine(const Command& command) {
	    std::string result;
	    
	    switch(command.commandName()) {
	        case CommandName::DEL:
	            result = "DEL;";
	            break;
	        case CommandName::GET:
	            result = "GET;";
	            break;
	        case CommandName::SET:
	            result = "SET;";
	            break;
	        default:
	            throw std::invalid_argument("Invalid command name in commandToText");
	    }
	    
	    result += command.key().key();
	    
	    if (command.commandName() == CommandName::SET) {
	        result += ";" + command.value().value().value();
	    }
	    
	    return result;
	}

	Command commandFromLine(std::string_view line) {
	    if (line.empty()) {
	        throw std::invalid_argument("Empty command");
	    }
		auto splited_line = split(line, ';');
		
		if (splited_line.size() < 2) {
			throw std::invalid_argument("Incorrect line format");
		}

		std::string_view cmd_name = splited_line[0];
		std::string_view key = splited_line[1];

		if (cmd_name == "SET") {
			if (splited_line.size() != 3 || splited_line[2].empty()) {
				throw std::invalid_argument("Command SET must have key and value");
			}
			return Command::setCommand(Key(key), Value(splited_line[2]));
		} else if (cmd_name == "DEL") {
			if (splited_line.size() != 2) {
				throw std::invalid_argument("Command DEL must have only key");
			}
			return Command::delCommand(Key(key));
		} else if (cmd_name == "GET") {
			if (splited_line.size() != 2) {
				throw std::invalid_argument("Command GET must have only key");
			}
			return Command::getCommand(Key(key));
		}
		throw std::invalid_argument("Incorrect command");  
	}
}
