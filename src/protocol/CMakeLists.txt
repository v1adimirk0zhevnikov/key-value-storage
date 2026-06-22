#src/protocol/CMakeLists.txt
add_library(protocol STATIC
	ParsingUtils.cpp
	IProtocolReader.hpp
	ConsoleProtocolReader.cpp
	FileProtocolReader.cpp
	ProtocolException.cpp
)

target_include_directories(protocol PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(protocol PUBLIC core)
