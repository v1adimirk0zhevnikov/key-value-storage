#ifndef MY_PROTOCOL_PARSING_UTILS_HPP
#define MY_PROTOCOL_PARSING_UTILS_HPP
#include "Command.hpp"
#include <string>
#include <string_view>
#include <vector>

namespace parsing{
	[[nodiscard]] std::vector<std::string_view> split(std::string_view line, const char delimeter);
	[[nodiscard]] std::string commandToLine(const Command& command);
	[[nodiscard]] Command commandFromLine(std::string_view text);
}

#endif
