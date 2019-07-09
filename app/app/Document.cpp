#include "Document.h"

using namespace std;



Document::Document(string name) :
	name(name)
{}

Document::Document(string name, State* s) :
	name(name),
	current_state(s){}

Document::~Document()
{
	for (State& s : states)
		delete &s;

	for (Transition& t : transitions)
		delete &t;

	for (auto i = fields.begin(); i != fields.end(); i++)
		delete &(*i);

	for (Action& a : actions)
		delete &a;
}

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
bool Document::action_exsist(Action a)
{
	for (Action aa : actions)
		if (a.get_name() == aa.get_name())
			return true;
	return false;
}
Action * Document::find_action(Action a)
{
	for (auto aa = actions.begin(); aa != actions.end(); aa++)
		if (a.get_name() == (*aa).get_name())
			return &(*aa);

	return NULL;

}
Transition * Document::corresponding_trans(Action & a)
{
	for (Transition& t : current_state->get_transitions())
		if (t.get_action()->get_name() == a.get_name())
			return &t;

	return NULL;

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


