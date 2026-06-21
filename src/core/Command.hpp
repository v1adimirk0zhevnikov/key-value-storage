#ifndef COMMAND_CLASS_HPP
#define COMMAND_CLASS_HPP
#include <cstdint>
#include <optional>
#include <SFML/Network.hpp>
#include "Key.hpp"
#include "Value.hpp"

enum class CommandName : uint8_t {
	UNKNOWN = 0x0,
	SET = 0x1,
	GET = 0x2,
	DEL = 0x3

	// Можно добавить новую 
};


class Command final {
private:
	CommandName m_command_name;
	Key m_key;
	std::optional<Value> m_value;
	explicit Command(const CommandName& name, const Key& key, std::optional<Value> value);
public:
	Command() : m_command_name(CommandName::UNKNOWN), m_key(Key("")), m_value(std::nullopt) {}
	
	[[nodiscard]] static Command setCommand(const Key& key, const Value& value);
	[[nodiscard]] static Command getCommand(const Key& key);
	[[nodiscard]] static Command delCommand(const Key& key);
	
	Command(const Command& other) = default;
    Command(Command&& other) = default;
    Command& operator=(const Command& other) = default;
    Command& operator=(Command&& other) = default;
	~Command() = default;

	bool operator==(const Command& other) const;

	[[nodiscard]] Key key() const;
	[[nodiscard]] std::optional<Value> value() const;
	[[nodiscard]] CommandName commandName() const;
};

sf::Packet& operator<<(sf::Packet& packet, const Command& command);
sf::Packet& operator>>(sf::Packet& packet, Command& command);

#endif
