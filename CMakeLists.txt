#Root CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(key-value-storage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set_target_properties(gtest gtest_main gmock gmock_main
	PROPERTIES FOLDER "external")

find_package(SFML 2.5 COMPONENTS network REQUIRED)


add_subdirectory(src/core)
add_subdirectory(src/storage)
add_subdirectory(src/protocol)
add_subdirectory(src/server)
add_subdirectory(src/client)
add_subdirectory(tests)
add_subdirectory(server-app)
add_subdirectory(client-app)
