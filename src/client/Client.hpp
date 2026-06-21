#ifndef CLIENT_CLASS_HPP
#define CLIENT_CLASS_HPP

#include <SFML/Network.hpp>
#include "Command.hpp"

class Client final {
private:
    sf::TcpSocket m_socket;
public:
    void connect(const std::string& host, uint16_t port);
    void disconnect();
        
   	[[nodiscard]] bool isConnected() const;
        
	[[nodiscard]] std::string sendCommand(const Command& cmd);
};


#endif
