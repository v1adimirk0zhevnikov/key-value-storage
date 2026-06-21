#include "Key.hpp"

Key::Key(std::string_view key) : m_key(key) {}

bool Key::operator==(const Key& other) const {
	return m_key == other.m_key;
}

const std::string& Key::key() const {
	return m_key;
}

sf::Packet& operator<<(sf::Packet& packet, const Key& key) {
	return packet << key.key();
}

sf::Packet& operator>>(sf::Packet& packet, Key& key) {
	std::string key_string;
	packet >> key_string;

	key = Key(key_string);
	return packet;
}
