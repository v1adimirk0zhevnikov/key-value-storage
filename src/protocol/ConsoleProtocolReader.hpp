#ifndef CONSOLE_PROTOCOL_READER_CLASS_HPP
#define CONSOLE_PROTOCOL_READER_CLASS_HPP
#include "IProtocolReader.hpp"

class ConsoleProtocolReader final : public IProtocolReader {
public:
	[[nodiscard]] std::optional<Command> next() override;
};


#endif
