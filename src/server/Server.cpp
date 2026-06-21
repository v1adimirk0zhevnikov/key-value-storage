#include "Server.hpp"
#include "SetHandler.hpp"
#include "GetHandler.hpp"
#include "DelHandler.hpp"
#include <iostream>

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
    std::cout << "Waiting for clients" << std::endl;
    
    while (true) {
        sf::TcpSocket client;
        
        if (m_listener.accept(client) != sf::Socket::Done) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        std::cout << "Client connected" << std::endl;
        handleClient(client);
        std::cout << "Client disconnected" << std::endl;
    }
}

void Server::handleClient(sf::TcpSocket& client) {
    while (true) {
        sf::Packet packet;
        const sf::Socket::Status status = client.receive(packet);
        
        if (status == sf::Socket::Disconnected) {
            break;
        }
        
        if (status != sf::Socket::Done) {
            continue;
        }
        
        if (packet.getDataSize() == 0) {
            continue;
        }
        
        Command command;
        
        if (!(packet >> command)) {
            sf::Packet error_packet;
            error_packet << "ERROR: Invalid command format";
            client.send(error_packet);
            continue;
        }
        
        if (command.commandName() == CommandName::UNKNOWN) {
            sf::Packet error_packet;
            error_packet << "ERROR: Invalid command";
            client.send(error_packet);
            continue;
        }
        
        std::string response = m_dispatcher.execute(command, *m_storage);
        
        sf::Packet response_packet;
        response_packet << response;
        
        if (client.send(response_packet) != sf::Socket::Done) {
            std::cout << "Failed to send response, client disconnected" << std::endl;
            break;
        }
    }
}

void Server::stop() {
    m_listener.close();
}
