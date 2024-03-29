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
	for (State* s : states)
		delete s;

	for (Transition& t : transitions)
		delete &t;

	for (auto i = fields.begin(); i != fields.end(); i++)
		delete &(*i);

	for (Action& a : actions)
		delete &a;
}

void Document::add_state(State* s)
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
void Document::set_current_state(State * _state, bool error)
{
	current_state = _state;
	emit model_updated(error);
}
void Document::set_states(std::list<State*>& stat)
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
	for (Transition* t : current_state->get_transitions())
		if (t->get_action()->get_name() == a.get_name())
			return t;

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

list<State*>& Document::get_states()
{
	return states;
}
set<Field>& Document::get_fields()
{
	return fields;
}

void Document::clear_fields()
{
	for (Field* f : current_state->get_deny_fields())
		f->set_text("");

	for (Field* f : current_state->get_mandatory_fields())
		f->set_text("");

	for (Field* f : current_state->get_hide_fields())
		f->set_text("");

	emit model_updated(false);
}

void Document::update_state_fields(State * prev_state)
{

	for (int i = 0; i < current_state->get_mandatory_fields().size(); i++)
		current_state->get_mandatory_fields()[i]->set_text(prev_state->get_mandatory_fields()[i]->get_text());

	for (int i = 0; i < current_state->get_hide_fields().size(); i++)
		current_state->get_hide_fields()[i]->set_text(prev_state->get_hide_fields()[i]->get_text());

	for (int i = 0; i < current_state->get_deny_fields().size(); i++)
		current_state->get_deny_fields()[i]->set_text(prev_state->get_deny_fields()[i]->get_text());

}


