#include <iostream>
#include <string>
#include <SFML/Network.hpp>
#include "Client.hpp"
#include "ParsingUtils.hpp"

int main() {
	Client client;

	client.connect("127.0.0.1", 8888);
	if (!client.isConnected()) {
		std::cout << "Cannot connect, change port or host" << std::endl;
		return 1;
	}

	Command cmd = Command::setCommand(Key("key"), Value("value"));
	std::string resp = client.sendCommand(cmd);
	std::cout << resp << std::endl;

	cmd = Command::setCommand(Key("key2"), Value("Value"));
	resp = client.sendCommand(cmd);
	std::cout << resp << std::endl;

	cmd = Command::getCommand(Key("key"));
	resp = client.sendCommand(cmd);
	std::cout << resp << std::endl;
	client.disconnect();
	
	
	return 0;
}
