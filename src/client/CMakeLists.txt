add_library(client STATIC
	Client.cpp)

target_include_directories(client PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(client PRIVATE sfml-network core protocol)
