#ifndef CUSTOM_STATE_1_H
#define CUSTOM_STATE_1_H

#include "../../../deps/state_machine/state_machine/include/state_machine/IState.h"

#include <functional>
#include <string>

namespace sm
{
class State_1 : public IState
{
public:
	State_1(const Edge* edge_a, const Edge* edge_b, const Edge* edge_c, std::string input_stream);

	const Edge* RunState() override;

	void OnEntry() override;

	const char* Name() const override;

private:
	const Edge* m_edge_a;
	const Edge* m_edge_b;
	const Edge* m_edge_c;
	std::string m_name;
	std::string p_input_stream;
};
} // namespace sm

#endif //STATE_MACHINE_CALLABLE_STATE_H