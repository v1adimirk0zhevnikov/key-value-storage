#include "FileProtocolReader.hpp"
#include "ParsingUtils.hpp"

FileProtocolReader::FileProtocolReader(std::string_view filename) : 
	m_input_stream(filename.data()), m_line_numbers(0) {
	if (!m_input_stream.is_open()) {
    	throw std::runtime_error("Cannot open file");
    }
}

std::optional<Command> FileProtocolReader::next() {
	std::string input_line;   
    if (std::getline(m_input_stream, input_line)) {
	    m_line_numbers++;
	    if (input_line.empty()) {
	    	throw std::invalid_argument("READER ERROR: line - " + std::to_string(m_line_numbers) + " empty line");
	    }
	    try {
	    	return parsing::commandFromLine(input_line);
	    } catch (const std::exception& e) {
	    	throw std::invalid_argument("READER ERROR: line - " + std::to_string(m_line_numbers) + ": " + e.what());
	    }
    }
	return std::nullopt;
}
