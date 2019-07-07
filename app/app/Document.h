#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <string>
#include <list>

#include "Field.h"
#include "State.h"
#include "Transition.h"

class State;
class Transition;

class Document {
public:
	Document() {}
	Document(std::string _name);
	Document(std::string _name, State* s);
	
	void add_transition(Transition& t);
	void add_field(Field& f);
	void add_action(Action& a);
	void add_state(State& s);
	
	void set_name(std::string _name) { name = _name; };
	void set_current_state(State * _state) { current_state = _state; };
	
	void set_states(std::list<State>& stat);
	void set_transitions(std::list<Transition>& tran);
	void set_fields(std::list<Field>& fil);
	void set_actions(std::list<Action>& ac);
	
	std::list<Action>& get_actions();
	std::list<Transition>& get_transitions();
	std::list<State>& get_states();
	std::list<Field>& get_fields();
	std::string get_name() { return name; };
	State* get_current_state() { return current_state; };

private:
	std::string name;
	
	State* current_state;
	
	std::list<State> states;
	std::list<Transition> transitions;
	std::list<Field> fields;
	std::list<Action> actions;
};


#endif // !_DOCUMENT_H_