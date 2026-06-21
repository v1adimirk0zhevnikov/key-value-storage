#ifndef SERVER_CLASS_HPP
#define SERVER_CLASS_HPP
#include <SFML/Network.hpp>
#include "CommandDispatcher.hpp"
#include "IStorage.hpp"

class Server final {
private:
	CommandDispatcher m_dispatcher;
	std::unique_ptr<IStorage> m_storage;
	sf::TcpListener m_listener;

	void handleClient(sf::TcpSocket& client);
	
public:
	explicit Server(std::unique_ptr<IStorage> storage);
	Server(const Server& other) = delete;
	Server& operator=(const Server& other) = delete;
	~Server() = default;	

	void launch();
	void start(uint16_t port);
	void stop();
};

#endif
