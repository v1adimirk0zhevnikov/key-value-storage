#include "ConsoleProtocolReader.hpp"
#include "ParsingUtils.hpp"
#include "ProtocolException.hpp"
#include <iostream>

std::optional<Command> ConsoleProtocolReader::next() {
	std::string input_line;

	if(!std::getline(std::cin, input_line)) {
		return std::nullopt;
	}

	if(input_line.empty()) {
		throw ProtocolException("[CLIENT] > Incorrect line format : empty");
	}

	if (input_line == "quit" || input_line == "exit") {
		return std::nullopt;
	}

	try {
		return parsing::commandFromLine(input_line);
	} catch(const std::invalid_argument& e) {
		std::string msg = "[CLIENT] > ";
		msg += e.what();
		throw ProtocolException(msg);
	}
}
