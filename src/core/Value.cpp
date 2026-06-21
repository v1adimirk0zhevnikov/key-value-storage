#include "Value.hpp"

Value::Value(std::string_view value) : m_value(value) {}

bool Value::operator==(const Value& other) const {
	return m_value == other.m_value;
}

const std::string& Value::value() const {
	return m_value;
}

sf::Packet& operator<<(sf::Packet& packet, const Value& value) {
	return packet << value.value();
}

sf::Packet& operator>>(sf::Packet& packet, Value& value) {
	std::string value_string;
	packet >> value_string;

	value = Value(value_string);
	return packet;
}
