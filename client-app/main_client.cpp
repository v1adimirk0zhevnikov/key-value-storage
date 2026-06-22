#include <iostream>
#include <string>
#include <SFML/Network.hpp>
#include "FileProtocolReader.hpp"
#include "ConsoleProtocolReader.hpp"
#include "ProtocolException.hpp"
#include "Client.hpp"
#include "ParsingUtils.hpp"

int main() {
	Client client;

	client.connect("127.0.0.1", 8888);
	if (!client.isConnected()) {
		std::cout << "[CLIENT] > Cannot connect, change port or host" << std::endl;
		return 1;
	}

	std::cout << "[CLIENT] > Connected to server. \"quit\" or \"exit\" to exit):\n";
	std::cout << "[CLIENT] > Examples:\n";
	std::cout << "[CLIENT] > SET;key;value\n";
	std::cout << "[CLIENT] > GET;key\n";
	std::cout << "[CLIENT] > DEL;key\n\n";

	std::string input_line;
	std::cout << "[CLIENT] > ";
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
			std::cout << "[CLIENT] > " << e.what() << std::endl;
		}
		std::cout << "[CLIENT] > ";
	}

	client.disconnect();
	std::cout << "Disconnected.\n";
	
	return 0;
}
/*
int main(int argc, char* argv[]) {
	Client client;
    client.connect("127.0.0.1", 8888);
    if (!client.isConnected()) {
    	std::cout << "[CLIENT] > Cannot connect, change port or host" << std::endl;
    	return 1;
    }
    std::unique_ptr<IProtocolReader> reader;

	try {
		if (argc > 1) {
			std::cout << "File" << std::endl;
	    	reader = std::make_unique<FileProtocolReader>(argv[1]);
		} else {
			std::cout << "Console" << std::endl;
	    	reader = std::make_unique<ConsoleProtocolReader>();
	    }
	} catch (const std::exception& e) {
		std::cout << "[CLIENT] > ERROR: " << e.what() << std::endl;
	    return 1;
	}

	std::cout << "[CLIENT] > Connected to server. \"quit\" or \"exit\" to exit\n";
	std::cout << "[CLIENT] > Examples:\n";
	std::cout << "[CLIENT] > SET;key;value\n";
	std::cout << "[CLIENT] > GET;key\n";
	std::cout << "[CLIENT] > DEL;key\n\n";

	while (true) {
		try {
			std::cout << "[CLIENT] > ";
 			std::optional<Command> command = reader->next();
	
	        if (!command_opt.has_value()) {
	        	break; 
	        }
	        std::string resp = client.sendCommand(command.value());
	        std::cout << "[SERVER] > " <<  resp << std::endl;
	
	        } catch (const ProtocolException& e) {
	            std::cout << e.what() << std::endl;
	        } catch (const std::exception& e) {
	            std::cout <<  e.what() << std::endl;
	            break;
	        }
	    }
	
	client.disconnect();
	std::cout << "[CLIENT] > Disconnected.\n";

	return 0;
}*/
