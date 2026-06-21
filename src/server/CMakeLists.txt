#server/CMakeLists.txt
add_library(server STATIC
    ICommandHandler.hpp
    GetHandler.cpp
    SetHandler.cpp
    DelHandler.cpp
    CommandDispatcher.cpp
    Server.cpp
	)
	
target_include_directories(server PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(server PRIVATE storage core protocol sfml-network)
