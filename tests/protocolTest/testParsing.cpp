#include <gtest/gtest.h>
#include "ParsingUtils.hpp"

TEST(TestParsing, splitTest) {
	std::string_view strr = "Hello World";
	auto res = parsing::split(strr, ' ');
	EXPECT_EQ(res.size(), 2);
	EXPECT_EQ(res[0], "Hello");
	EXPECT_EQ(res[1], "World");


	std::string_view strr2 = "GET;key";
	res = parsing::split(strr2, ';');
	EXPECT_EQ(res.size(), 2);
	EXPECT_EQ(res[0], "GET");
	EXPECT_EQ(res[1], "key");
}

TEST(TestParsing, CommandToLineTest) {
	Command cmd = Command::setCommand(Key("k"), Value("v")); std::string check_cmd = "SET;k;v";
	Command cmd_del = Command::delCommand(Key("k1")); std::string check_cmd_del = "DEL;k1";
	Command cmd_get = Command::getCommand(Key("k2")); std::string check_cmd_get = "GET;k2";
	std::string x;
	EXPECT_THROW(x = parsing::commandToLine(Command()), std::invalid_argument);
	EXPECT_NO_THROW(x = parsing::commandToLine(cmd));
	EXPECT_EQ(x, check_cmd);
	EXPECT_NO_THROW(x = parsing::commandToLine(cmd_del));
	EXPECT_EQ(x, check_cmd_del);
	EXPECT_NO_THROW(x = parsing::commandToLine(cmd_get));
	EXPECT_EQ(x, check_cmd_get);	
}

TEST(TestParsing, CommandFromLineTest) {
	std::string_view empty = "";
	Command cmd;
	EXPECT_THROW(cmd = parsing::commandFromLine(empty), std::invalid_argument);
	std::string_view incorrect_m = "COMMAND";
	std::string_view incorrect_b = "COMMAND;kkk;vvvvv;qwerty";
	EXPECT_THROW(cmd = parsing::commandFromLine(incorrect_m), std::invalid_argument);
	EXPECT_THROW(cmd = parsing::commandFromLine(incorrect_b), std::invalid_argument);


	std::string_view good_cmd = "SET;key;value";
	EXPECT_NO_THROW(cmd = parsing::commandFromLine(good_cmd));
	EXPECT_EQ(cmd, Command::setCommand(Key("key"), Value("value")));
}
