#include "ProtocolException.hpp"

ProtocolException::ProtocolException(std::string_view message) :
m_message(std::string(message)) {}

const char* ProtocolException::what() const noexcept {
	return m_message.c_str();
}
