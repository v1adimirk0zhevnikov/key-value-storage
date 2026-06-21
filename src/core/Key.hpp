#ifndef KEY_CLASS_HPP
#define KEY_CLASS_HPP
#include <string>
#include <SFML/Network.hpp>

class Key final{
private:
	std::string m_key;
public:
	explicit Key(std::string_view key);
	Key& operator=(const Key& other) = default;
	~Key() = default;

	[[nodiscard]] bool operator==(const Key& other) const;
	[[nodiscard]] const std::string& key() const;
};

struct KeyHash {
	size_t operator()(const Key& key) const {
		return std::hash<std::string>{}(key.key());
	}	
};

sf::Packet& operator<<(sf::Packet& packet, const Key& key);
sf::Packet& operator>>(sf::Packet& packet, Key& key);

#endif
