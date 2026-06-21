#include <iostream>
#include <SFML/Network.hpp>
#include <string>

#include "Key.hpp"
#include "Value.hpp"
#include "Server.hpp"
#include "DiscStorage.hpp"
#include "MemoryStorage.hpp"

int main() {
	std::filesystem::path directory_path = "storage";
	auto storage = std::make_unique<DiscStorage>(directory_path);

	Server server(std::move(storage));

	server.start(8888);
	server.launch();
	return 0;
}
