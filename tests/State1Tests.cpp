#include <gmock/gmock.h>
#include <gtest/gtest.h>

class ICharacterStream
{
public:
	~ICharacterStream(){}; //virtual destructor
	virtual char GetNextCharacter() = 0;
};

class ICharacterStreamMock : public ICharacterStream
{
public:
	MOCK_METHOD(char, GetNextCharacter, ());
};

class State1
{
public:
	State1(std::shared_ptr<ICharacterStream> input_stream)
    {

    }
};

class State1Tests : public testing::Test
{
    
};

TEST_F(State1Tests, construct_state1) 
{
    auto char_stream = std::make_shared<ICharacterStreamMock>();
    State1 state1(char_stream);
}

//EXPECT_CALL(*char_stream, GetNextCharacter()).WillOnce([](){return 'a';}); 