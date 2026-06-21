#include "Command.hpp"
#include <optional>

namespace {
	bool isValidCommandName(CommandName command_name) {
		switch(command_name) {
			case CommandName::SET:
			case CommandName::GET:
			case CommandName::DEL:
				return true;
			default:
				return false;
		}
	}
}

Command::Command(const CommandName& name, const Key& key, std::optional<Value> value) : 
	m_command_name(name), m_key(key), m_value(value) {}

Command Command::setCommand(const Key& key, const Value& value) {
	return Command(CommandName::SET, key, value);
}

Command Command::getCommand(const Key& key) {
	return Command(CommandName::GET, key, std::nullopt);
}

Command Command::delCommand(const Key& key) {
	return Command(CommandName::DEL, key, std::nullopt);
}

bool Command::operator==(const Command& other) const {
	return (m_command_name == other.m_command_name) &&
		   (m_value == other.m_value) &&
		   (m_key == other.m_key);
}

Key Command::key() const {
	return m_key;
}

std::optional<Value> Command::value() const {
	return m_value;
}

CommandName Command::commandName() const {
	return m_command_name;
}

namespace {
	sf::Packet& operator<<(sf::Packet& packet, CommandName name) {
		uint8_t value = static_cast<uint8_t>(name);
		return packet << value;
	}

	sf::Packet& operator>>(sf::Packet& packet, CommandName& name) {
		uint8_t value;
		packet >> value;

		switch(value) {
			case static_cast<uint8_t>(CommandName::SET):
			case static_cast<uint8_t>(CommandName::GET):
			case static_cast<uint8_t>(CommandName::DEL):
				name = static_cast<CommandName>(value);
				break;
			default:
				throw std::runtime_error("Invalid CommandName in Packet");
		}
		return packet;
	}
}


sf::Packet& operator<<(sf::Packet& packet, const Command& command) {
	packet << command.commandName();
	packet << command.key();

	if (command.commandName() == CommandName::SET) {
		if (command.value().has_value()) {
			packet << command.value().value();
		} else {
			throw std::invalid_argument("Impossible situation");
		}
	}
	return packet;
}

sf::Packet& operator>>(sf::Packet& packet, Command& command) {
	CommandName command_name;
	packet >> command_name;

	if(packet.getDataSize() == 0) {
		throw std::runtime_error("Defeated packet");
	}

	Key key = Key("");
	packet >> key;

	switch(command_name) {
		case CommandName::DEL: {
			command = Command::delCommand(key);
			break;
		}
		case CommandName::GET: {
			command = Command::getCommand(key);
			break;
		}
		case CommandName::SET: {
			Value value = Value("");
			packet >> value;
			command = Command::setCommand(key, value);
			break;
		}
		default: {
			throw std::runtime_error("Invalid situation");
			break;
		}
	}
	return packet;
}
