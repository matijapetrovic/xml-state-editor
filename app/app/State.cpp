#include "State.h"

using namespace std;

State::State(int _entity_id, string _display_name) :
	entity_id(_entity_id),
	display_name(_display_name)
{
}

State::State(const State & s)
{
	entity_id = s.entity_id;
	display_name = s.display_name;
	lifecycle_name = s.lifecycle_name;
	entity_name = s.entity_name;

	state_semantic = s.state_semantic;
	actions = s.actions;
	transitions = s.transitions;
	mandatory_fields = s.mandatory_fields;
	hide_fields = s.hide_fields;
	deny_modyfing_filds = s.deny_modyfing_filds;

}


void State::set_state_semantic(vector<StateSemantic>& ss)
{
	state_semantic = ss;
}
void State::set_actions(vector<Action>& act)
{
	actions = act;
}
void State::set_transitions(vector<Transition>& tr)
{
	transitions = tr;
}
void State::set_mandatory_fields(vector<Field>& mandatory)
{
	mandatory_fields = mandatory;
}
void State::set_hide_fields(vector<Field>& hide)
{
	hide_fields = hide;
}
void State::set_deny_fields(vector<Field>& deny)
{
	deny_modyfing_filds = deny;
}

void State::add_action(Action& a)
{
	actions.push_back(a);
}
void State::add_transition(Transition& t)
{
	transitions.push_back(t);
}
void State::add_mandatory_field(Field& f)
{
	mandatory_fields.push_back(f);
}
void State::add_hide_field(Field& hide)
{
	hide_fields.push_back(hide);
}
void State::add_deny_field(Field& deny)
{
	deny_modyfing_filds.push_back(deny);
}

void State::add_state_semantic(StateSemantic s)
{
	state_semantic.push_back(s);
}
