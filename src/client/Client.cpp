#include "Client.hpp"
void Client::connect(const std::string& host, uint16_t port) {
    m_socket.connect(host, port);
}
    
void Client::disconnect() {
	m_socket.disconnect();
}

bool Client::isConnected() const {
    return m_socket.getRemoteAddress() != sf::IpAddress::None;
}
    
std::string Client::sendCommand(const Command& cmd) {
	if (!isConnected()) {
		return "ERROR: Not connected";
	}
      
    sf::Packet packet;
    packet << cmd;
    m_socket.send(packet);
     
    sf::Packet response;
    m_socket.receive(response);
      
    std::string result;
    response >> result;
    return result;
}
