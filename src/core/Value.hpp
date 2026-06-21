#ifndef VALUE_CLASS_HPP
#define VALUE_CLASS_HPP
#include <string>
#include <string_view>
#include <SFML/Network.hpp>


class Value final {
private:
	std::string m_value;
public:
	explicit Value(std::string_view value);
	Value& operator=(const Value& other) = default;
	~Value() = default;

	[[nodiscard]] bool operator==(const Value& other) const;
	[[nodiscard]] const std::string& value() const;
};

sf::Packet& operator<<(sf::Packet& packet, const Value& value);
sf::Packet& operator>>(sf::Packet& packet, Value& value);


#endif
