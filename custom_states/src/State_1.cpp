#include "custom_states/State_1.h"

#include <stdexcept>
#include <iostream>
namespace sm
{
State_1::State_1(const Edge* edge_a, const Edge* edge_b, const Edge* edge_c, std::string input_stream)
    : m_edge_a(std::move(edge_a))
	, m_edge_b(std::move(edge_b))
	, m_edge_c(std::move(edge_c))
	// , m_name(std::move(name))
	, p_input_stream(std::move(input_stream))

{
	m_name = "State_1";
	// edge_a->transition_name = "state_1 transitions on A to state_2";
	// edge_b->transition_name = "state_1 no transitions on B";
	// edge_c->transition_name = "state_1 transitions on C to state_3";
	if (!p_input_stream.empty())
	{
		throw std::invalid_argument("State_1: input pointer can't be null");
	}
}

const Edge* State_1::RunState()
{
	char input = p_input_stream[0];
	p_input_stream.erase(0,1);
	
	if (input == 'a')
		return m_edge_a;
	if (input == 'b')
		return m_edge_b;
	if (input == 'c')
		return m_edge_c;

	throw std::invalid_argument("State_1: input_stream contains invalid token");

}

void State_1::OnEntry()
{
	std::cout << "State_1: On Entry Called\n";
}

const char* State_1::Name() const
{
	return m_name.c_str();
}

} // namespace sm