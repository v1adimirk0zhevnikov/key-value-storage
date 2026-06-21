#src/storage/CMakeLists.txt
add_library(storage STATIC
	IStorage.hpp
	DiscStorage.cpp
	MemoryStorage.cpp
	StorageException.cpp)

target_include_directories(storage PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(storage PRIVATE sfml-system core)
