/**
 * @brief - Make sure gtest links and we can observe a passing and a failing test
 * 
 */
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class GTestExample : public testing::Test
{
};

using ::testing::Return;

/**
 * @brief Show how to use a method on a mock - mocks are frequently in their own file. Illustrated in the same file as usage for simplicity
 * 
 */
class ExampleClassWithMocks
{
public:
	MOCK_METHOD(const char*, Name, (), (const));
	MOCK_METHOD(int, Foo, (int));
};

TEST_F(GTestExample, passing_test)
{
	EXPECT_TRUE(true);
}

TEST_F(GTestExample, failing_test)
{
	EXPECT_TRUE(false);
}

TEST_F(GTestExample, use_a_mock_return)
{
	ExampleClassWithMocks example_mock;
	EXPECT_CALL(example_mock, Name()).WillOnce(Return("foo"));
	EXPECT_STREQ("foo", example_mock.Name());
}

TEST_F(GTestExample, use_a_mock_with_arg_expectations)
{
	ExampleClassWithMocks example_mock;
	//We are using these directly, but a mock would typically be used by the class under test
	EXPECT_CALL(example_mock, Foo(1)).WillOnce(Return(11));
    EXPECT_CALL(example_mock, Foo(27)).WillOnce(Return(42));

	EXPECT_EQ(11, example_mock.Foo(1));
    EXPECT_EQ(42, example_mock.Foo(27));
}