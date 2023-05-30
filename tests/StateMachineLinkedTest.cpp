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

TEST_F(StateMachineLinkedTests, abc_input_stream)
{
    std::string input_stream = "abc";

    sm::Edge state1_out_edge_a;
    sm::Edge state1_out_edge_b;
    sm::Edge state1_out_edge_c;
    state1_out_edge_a.transition_name = "state1_to_state2";
    state1_out_edge_b.transition_name = "no_transition";
    state1_out_edge_c.transition_name = "state1_to_state3";
    uint32_t state1_cnt = 0;

    sm::Edge state2_out_edge_a;
    sm::Edge state2_out_edge_b;
    sm::Edge state2_out_edge_c;
    state2_out_edge_a.transition_name = "state2_to_state2";
    state2_out_edge_b.transition_name = "state2_to_state1";
    state2_out_edge_c.transition_name = "state2_to_state3";
    uint32_t state2_cnt = 0;

    sm::Edge state3_out_edge_a;
    sm::Edge state3_out_edge_b;
    sm::Edge state3_out_edge_c;
    state3_out_edge_a.transition_name = "state3_to_state1";
    state3_out_edge_b.transition_name = "state3_to_state1";
    state3_out_edge_c.transition_name = "no_transition";
    uint32_t state3_cnt = 0;

    auto state1 = std::make_shared<sm::CallableState>([&](){
        state1_cnt++;
        char input = input_stream[0];
        input_stream.erase(0,1);
        if (input == 'a')
            return &state1_out_edge_a;
        if (input == 'b')
            return &state1_out_edge_b;
        if (input == 'c')
            return &state1_out_edge_c;
    }, "state1");

    auto state2 = std::make_shared<sm::CallableState>([&](){
        state2_cnt++;
        char input = input_stream[0];
        input_stream.erase(0,1);
        if (input == 'a')
            return &state2_out_edge_a;
        if (input == 'b')
            return &state2_out_edge_b;
        if (input == 'c')
            return &state2_out_edge_c;
    }, "state2");

    auto state3 = std::make_shared<sm::CallableState>([&](){
        state3_cnt++;
        char input = input_stream[0];
        input_stream.erase(0,1);
        if (input == 'a')
            return &state3_out_edge_a;
        if (input == 'b')
            return &state3_out_edge_b;
        if (input == 'c')
            return &state3_out_edge_c;
    }, "state3");

    state1_out_edge_a.next_state = state2;
    state1_out_edge_b.next_state = nullptr;
    state1_out_edge_c.next_state = state3;

    state2_out_edge_a.next_state = state2;
    state2_out_edge_b.next_state = state1;
    state2_out_edge_c.next_state = state3;

    state3_out_edge_a.next_state = state1;
    state3_out_edge_b.next_state = state1;
    state3_out_edge_c.next_state = nullptr;

    sm::StateMachine machine(state1);

    EXPECT_EQ(0, state1_cnt);
    EXPECT_EQ(0, state2_cnt);

    while(!input_stream.empty()){
        std::cout << "Running input " << input_stream << "\n";
        machine.RunStateMachine();
    }
    std::cout << "Input is empty\n";
    EXPECT_EQ(2, state1_cnt);
    EXPECT_EQ(1, state2_cnt);
    EXPECT_EQ(0, state3_cnt);
}