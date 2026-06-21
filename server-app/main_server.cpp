#include <iostream>
#include <SFML/Network.hpp>
#include <string>

#include "Server.hpp"
#include "MemoryStorage.hpp"

int main() {
	auto storage = std::make_unique<MemoryStorage>();

	Server server(std::move(storage));

	server.start(8888);
	server.launch();
	return 0;
}
