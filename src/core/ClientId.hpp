#ifndef CLIENT_IDENTIFICATOR_CLASS_HPP
#define CLIENT_IDENTIFICATOR_CLASS_HPP
#include <cstdint>
#include <cstddef>
#include <functional>
#include <SFML/Network.hpp>


class ClientId final{
private:
	uint64_t m_id;
public:
	explicit ClientId(uint64_t id);

	ClientId(const ClientId& other) = default;
	ClientId& operator=(const ClientId& other) = default;
	ClientId(ClientId&&) = default;
	ClientId& operator=(ClientId&&) = default;
	~ClientId() = default;

	[[nodiscard]] bool operator==(const ClientId& other) const;
	[[nodiscard]] uint64_t clientId() const;
};


struct ClientIdHash {
	size_t operator()(const ClientId& id) {
		return std::hash<uint64_t>{}(id.clientId());
	}
};

sf::Packet& operator<<(sf::Packet& packet, const ClientId& client_id);
sf::Packet& operator>>(sf::Packet& packet, ClientId& client_id);


#endif
