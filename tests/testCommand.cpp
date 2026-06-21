#include <gtest/gtest.h>
#include <optional>
#include "Command.hpp"

TEST(TestCommand, ConstructorAndGetterTest) {
	Command cmd = Command::delCommand(Key("key"));
	EXPECT_EQ(cmd.commandName(), CommandName::DEL);
	EXPECT_EQ(cmd.key(), Key("key"));
	EXPECT_FALSE(cmd.value().has_value());

	Command cmd2;
	EXPECT_EQ(cmd2.commandName(), CommandName::UNKNOWN);
	EXPECT_EQ(cmd2.key(), Key(""));
	EXPECT_FALSE(cmd2.value().has_value());
}

TEST(TestCommand, OperatorTest) {
	Command cmd1 = Command::delCommand(Key("del_cmd"));
	Command cmd2 = Command::delCommand(Key("del_cmd"));	
	EXPECT_TRUE(cmd1 == cmd2);
}
