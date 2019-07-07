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
	
	void set_name(std::string _name) { name = _name; };
	void set_state(State * _state) { state = _state; };
	
	void set_transitions(std::list<Transition>& tran);
	void set_fields(std::list<Field>& fil);
	void set_actions(std::list<Action>& ac);
	
	std::list<Action>& get_actions();
	std::list<Transition>& get_transitions();
	std::list<Field>& get_fields();
	std::string get_name() { return name; };
	State* get_state() { return state; };

private:
	std::string name;
	
	State* state;
		
	std::list<Transition> transitions;
	std::list<Field> fields;
	std::list<Action> actions;
};


#endif // !_DOCUMENT_H_