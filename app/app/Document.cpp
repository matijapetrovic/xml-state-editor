#include "Document.h"

using namespace std;



Document::Document(string name) :
	name(name)
{}

Document::Document(string name, State* s) :
	name(name),
	current_state(s){}

void Document::add_state(State * s)
{
	states.push_back(s);
}
void Document::add_transition(Transition& t)
{
	transitions.push_back(t);
}
void Document::add_field(Field& f)
{
	fields.push_back(f);
}
void Document::add_action(Action& a)
{
	actions.push_back(a);
}
void Document::set_states(std::list<State*>& stat)
{
	states = stat;
}
void Document::set_transitions(list<Transition> &tran)
{
	transitions = tran;
}
void Document::set_fields(list<Field>& fil)
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

list<State*>& Document::get_states()
{
	return states;
}
list<Field>& Document::get_fields()
{
	return fields;
}
list<State*>& Document::get_states()
{
	return states;
}

