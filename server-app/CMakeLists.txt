#server-app/CMakeLists.txt
add_executable(server_app main_server.cpp)

target_link_libraries(server_app PRIVATE core storage protocol sfml-network server)

