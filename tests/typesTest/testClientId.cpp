#include <gtest/gtest.h>
#include <memory>
#include "ClientId.hpp"


TEST(TestClientId, ConstructorAndGetterTest) {
	ClientId id = ClientId(123);
	EXPECT_EQ(id.clientId(), 123);

	ClientId id_2(std::move(ClientId(222)));
	EXPECT_EQ(id_2.clientId(), 222);
	
}


TEST(TestClientId, OperatorTest) {
	ClientId testid = ClientId(1231213);
	ClientId testid2 = ClientId(1231213);
	ClientId testid3 = ClientId(0);
	EXPECT_TRUE(testid2 == testid);
	EXPECT_FALSE(testid3 == testid);
}
