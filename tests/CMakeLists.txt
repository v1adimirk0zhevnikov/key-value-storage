#tests/CMakeLists.txt
add_executable(tests
	test.cpp
	typesTest/testClientId.cpp
	typesTest/testCommand.cpp
	protocolTest/testParsing.cpp
)

target_link_libraries(tests PRIVATE
	core
	GTest::gtest_main
	protocol
	sfml-system
	sfml-network
	)

include(GoogleTest)
gtest_discover_tests(tests)
