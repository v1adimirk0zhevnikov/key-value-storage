#ifndef MY_PROTOCOL_READER_CLASS_HPP
#define MY_PROTOCOL_READER_CLASS_HPP
#include "IProtocolReader.hpp"
#include <memory>
#include <fstream>

class FileProtocolReader final : public IProtocolReader{ 
private:
	std::ifstream m_input_stream;
	int m_line_numbers;
public:
	explicit FileProtocolReader(std::string_view filename);
	FileProtocolReader(const FileProtocolReader& other) = delete;
	FileProtocolReader& operator=(const FileProtocolReader& other) = delete;
	~FileProtocolReader() override = default;

	[[nodiscard]] std::optional<Command> next() override;
}; 

#endif
