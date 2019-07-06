#pragma once
#include <iostream>
#include <string>
#include <list>
#include <Action.h>
#include <Field.h>

using namespace std;

class Document {
public:
	Document();
	Document(string name);
	Document(string name, State s);
	void addTransition(Transition t);
	void addField(Field f);
	void addAction(Action a);
	State & state;

private:
	string name;
	list<Transition> transitions;
	list<Field> fields;
	list<Action> actions;
};