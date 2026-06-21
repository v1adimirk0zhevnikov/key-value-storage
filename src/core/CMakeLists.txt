#core/CMakeLists.txt
add_library(core STATIC
	Key.cpp
	Value.cpp
	Command.cpp)
	
target_include_directories(core PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(core PRIVATE sfml-system sfml-network storage)

