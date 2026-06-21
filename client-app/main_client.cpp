#include <iostream>
#include <string>
#include <SFML/Network.hpp>
#include "Client.hpp"
#include "ParsingUtils.hpp"

int main() {
	Client client;

	client.connect("127.0.0.1", 8888);
	if (!client.isConnected()) {
		std::cout << "[CLIENT] Cannot connect, change port or host" << std::endl;
		return 1;
	}

	std::cout << "Connected to server. \"quit\" or \"exit\" to exit):\n";
	std::cout << "Examples:\n";
	std::cout << "[CLIENT] > SET;key;value\n";
	std::cout << "[CLIENT] > GET;key\n";
	std::cout << "[CLIENT] > DEL;key\n\n";

	std::string input_line;
	while (std::getline(std::cin, input_line)) {
		if (input_line.empty()) {
			continue;
		}
		if (input_line == "quit" || input_line == "exit") {
			break;
		}

		try {
			Command cmd = parsing::commandFromLine(input_line);
			std::string resp = client.sendCommand(cmd);
			std::cout << "[SERVER] > " << resp << std::endl;
		

		} catch (const std::invalid_argument& e) {
			std::cout << "[CLIENT]" << e.what() << std::endl;
		}

		std::cout << "[CLIENT] > ";
	}

	client.disconnect();
	std::cout << "Disconnected.\n";
	
	return 0;
}
