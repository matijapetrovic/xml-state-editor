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
	Document();
	Document(std::string name);
	Document(std::string name, State* s);
	
	void addTransition(Transition t);
	void addField(Field f);
	void addAction(Action a);
	
	void setName(std::string _name) { name = _name; };
	void setState(State * _state) { state = _state; };
	
	void setTransitions(std::list<Transition>& tran);
	void setFields(std::list<Field>& fil);
	void setActions(std::list<Action>& ac);
	
	std::list<Action>& getActions();
	std::list<Transition>& getTransitions();
	std::list<Field>& getFields();
	std::string getName() { return name; };
	State* getState() { return state; };

private:
	std::string name;
	
	State* state;
	
	std::list<Transition> transitions;
	std::list<Field> fields;
	std::list<Action> actions;
};


#endif // !_DOCUMENT_H_