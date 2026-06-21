#ifndef FILE_PROTOCOL_READER_CLASS_HPP
#define FILE_PROTOCOL_READER_CLASS_HPP
#include <fstream>
#include "Command.hpp"
#include "IProtocolReader.hpp"

class FileProtocolReader final : public IProtocolReader {
	std::ifstream m_file;
};

#endif
