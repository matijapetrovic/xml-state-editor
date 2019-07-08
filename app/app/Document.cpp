#include "Document.h"

using namespace std;



Document::Document(string name) :
	name(name)
{}

Document::Document(string name, State* s) :
	name(name),
	current_state(s){}

void Document::add_state(State s)
{
	states.push_back(s);
}
void Document::add_transition(Transition t)
{
	transitions.push_back(t);
}
void Document::add_field(Field& f)
{
	fields.insert(f);
}
void Document::add_action(Action& a)
{
	actions.push_back(a);
}
void Document::set_current_state(State * _state)
{
	current_state = _state;
	emit model_updated();
}
void Document::set_states(std::list<State>& stat)
{
	states = stat;
}
void Document::set_transitions(list<Transition> &tran)
{
	transitions = tran;
}
void Document::set_fields(set<Field>& fil)
{
	fields = fil;
}
void Document::set_actions(list<Action>& ac)
{
	actions = ac;
}
list<Action>& Document::get_actions()
{
	return actions;
}
list<Transition>& Document::get_transitions()
{
	return transitions;
}

list<State>& Document::get_states()
{
	return states;
}
set<Field>& Document::get_fields()
{
	return fields;
}


