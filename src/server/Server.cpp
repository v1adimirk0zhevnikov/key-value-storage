#include "Server.hpp"
#include "SetHandler.hpp"
#include "GetHandler.hpp"
#include "DelHandler.hpp"
#include <iostream>
//500ДЕНЬ
Server::Server(std::unique_ptr<IStorage> storage) : m_storage(std::move(storage)) {
	m_dispatcher.addHandler(std::make_unique<SetHandler>());
	m_dispatcher.addHandler(std::make_unique<GetHandler>());
	m_dispatcher.addHandler(std::make_unique<DelHandler>());
}

void Server::start(uint16_t port) {
    if (m_listener.listen(port) != sf::Socket::Done) {
        throw std::runtime_error("Cannot bind port " + std::to_string(port));
    }
    std::cout << "Server started on port " << port << std::endl;
}

void Server::launch() {
    std::cout << "Waiting for clients..." << std::endl;
    
    while (true) {
        sf::TcpSocket client;
        
        if (m_listener.accept(client) != sf::Socket::Done) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }
        
        handleClient(client);
    }
}

void Server::handleClient(sf::TcpSocket& client) {
    std::cout << "Client connected" << std::endl;
    
    sf::Packet packet;
    if (client.receive(packet) != sf::Socket::Done) {
        std::cerr << "Receive failed" << std::endl;
        return;
    }
    
    Command command;
    packet >> command;
    
    if (command.commandName() == CommandName::UNKNOWN) {
        sf::Packet error_packet;
        error_packet << "ERROR: Invalid command";
        client.send(error_packet);
        return;
    }
    
    std::string response = m_dispatcher.execute(command, *m_storage);
    
    sf::Packet response_packet;
    response_packet << response;
    client.send(response_packet);
    
    std::cout << "Client disconnected" << std::endl;
}

void Server::stop() {
    m_listener.close();
}
