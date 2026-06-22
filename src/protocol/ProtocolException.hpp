#ifndef PROTOCOL_EXCEPTION_CLASS_HPP
#define PROTOCOL_EXCEPTION_CLASS_HPP
#include <exception>
#include <string_view>
#include <string>

class ProtocolException final : public std::exception {
private:
	std::string m_message;
public:
	explicit ProtocolException(std::string_view message);

	const char* what() const noexcept override;
};


#endif
