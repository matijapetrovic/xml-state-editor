#include "State.h"

using namespace std;

State::State(int _entity_id, string _display_name, Document* _document) :
	entity_id(_entity_id),
	display_name(_display_name),
	document(_document)   
{
}


void State::set_state_semantic(list<StateSemantic>& ss)
{
	state_semantic = ss;
}
void State::set_actions(list<Action>& act)
{
	actions = act;
}
void State::set_transitions(list<Transition>& tr)
{
	transitions = tr;
}
void State::set_mandatory_fields(list<Field>& mandatory)
{
	mandatory_fields = mandatory;
}
void State::set_hide_fields(list<Field>& hide)
{
	hide_fields = hide;
}
void State::set_deny_fields(list<Field>& deny)
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

void State::add_transition_id(int i)
{
	transitions_ids.push_back(i);
}

void State::add_state_semantic(StateSemantic s)
{
	state_semantic.push_back(s);
}
