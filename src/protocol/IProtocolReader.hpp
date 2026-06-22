#ifndef INTERFACE_PROTOCOL_READER_HPP
#define INTERFACE_PROTOCOL_READER_HPP
#include <optional>
#include "Command.hpp"

class IProtocolReader {
public:
	virtual ~IProtocolReader() = default;
	[[nodiscard]] virtual std::optional<Command> next() = 0;
};


#endif
