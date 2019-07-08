#include "State.h"

using namespace std;


State::State(int _entity_id, string _display_name, Document* _document) :
	entity_id(_entity_id),
	display_name(_display_name),
	document(_document)   
{
}

State::State(const State & s)
{
	entity_id = s.entity_id;
	display_name = s.display_name;
	document = s.document;
	lifecycle_name = s.lifecycle_name;
	entity_name = s.entity_name;

	transitions_ids = s.transitions_ids;
	state_semantic = s.state_semantic;
	actions = s.actions;
	transitions = s.transitions;
	mandatory_fields = s.mandatory_fields;
	hide_fields = s.hide_fields;
	deny_modyfing_filds = s.deny_modyfing_filds;

}

Action* State::find_action(std::string name)
{
	list<Action>::iterator iterator;
	for (iterator = actions.begin(); iterator != actions.end(); iterator++)
	{
		if (iterator->get_label().compare(name) == 0) {
			Action* act = (Action*)&iterator;
			return act;
		}
			
	}
	return nullptr;
}

Transition* State::find_transition(int entity) {
	
	std::list<Transition>::iterator iterator;
	for (iterator = transitions.begin(); iterator != transitions.end(); iterator++)
	{
		if ((*iterator).get_entity_id() == entity) {
			Transition* tran = (Transition*)&iterator;
			return tran;
		}
	}
	return nullptr;
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
