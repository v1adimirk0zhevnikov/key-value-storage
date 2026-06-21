#ifndef STORAGE_EXCEPTION_CLASS_HPP
#define STORAGE_EXCEPTION_CLASS_HPP

#include <exception>
#include <string>
#include <string_view>

class StorageException final : public std::exception {
private:
	std::string m_message;
public:
	explicit StorageException(std::string_view message);

	const char* what() const noexcept override;
};

#endif
