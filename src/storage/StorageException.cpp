#include "StorageException.hpp"

StorageException::StorageException(std::string_view message) : m_message(std::string(message)) {}

const char* StorageException::what() const noexcept {
	return m_message.c_str();
}
