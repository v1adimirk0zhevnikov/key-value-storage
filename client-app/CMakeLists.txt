#cleint-app/CMakeLists.txt
add_executable(client_app main_client.cpp)

target_link_libraries(client_app PRIVATE core protocol client sfml-network)
