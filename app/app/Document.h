#pragma once
#include <iostream>
#include <string>
#include <list>
#include <IR.h>
#include <Field.h>
#include <State.h>

using namespace std;


class Document {
public:
	Document();
	Document(string name);
	Document(string name, State* s);
	void addTransition(Transition t);
	void addField(Field f);
	void addAction(Action a);
	State * state;
	void setName(string _name) { name = _name; };
	void setState(State * _state) { state = _state; };
	string getName() { return name; };
	State* getState() { return state; };

	void setTransitions(Transitions& tran);
	void setFields(Fields& fil);
	void setActions(Actions& ac);
	Actions& getActions();
	Transitions& getTransitions();
	Fields& getFields();

private:
	string name;
	Transitions transitions;
	Fields fields;
	Actions actions;
};