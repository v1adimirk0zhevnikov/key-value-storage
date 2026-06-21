#ifndef INTERFACE_PROTOCOL_READER_CLASS_HPP
#define INTERFACE_PROTOCOL_READER_CLASS_HPP
#include "ClientId.hpp"
#include "Command.hpp"


class IProtocolReader{
public:
	virtual ~IProtocolReader() = defautl;
	virtual std::optional<Command> next() = 0;
};


#endif
