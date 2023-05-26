/**
 * @brief A test that is linked against the state machine lib and uses the major classes
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "state_machine/CallableState.h"
#include "state_machine/StateMachine.h"


class StateMachineLinkedTests: public ::testing::Test
{

};

TEST_F(StateMachineLinkedTests, statemachine_useclasses)
{
    sm::Edge state1_out_edge;
    state1_out_edge.transition_name = "state1_to_state2";
    uint32_t state1_cnt = 0;

    sm::Edge state2_out_edge;
    state2_out_edge.transition_name = "state2_to_state1";
    uint32_t state2_cnt = 0;

    auto state1 = std::make_shared<sm::CallableState>([&](){
        state1_cnt++;
        return &state1_out_edge;
    }, "state1");

    auto state2  = std::make_shared<sm::CallableState>([&](){
        state2_cnt++;
        return &state2_out_edge;
    }, "state2");

    state1_out_edge.next_state = state2;
    state2_out_edge.next_state = state1;

    sm::StateMachine machine(state1);

    EXPECT_EQ(0, state1_cnt);
    EXPECT_EQ(0, state2_cnt);

    machine.RunStateMachine();
    machine.RunStateMachine();

    EXPECT_EQ(1, state1_cnt);
    EXPECT_EQ(1, state2_cnt);
}
