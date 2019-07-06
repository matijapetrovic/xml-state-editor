#pragma once
#include <iostream>
#include <string>
#include <Action.h>
using namespace std;

class State {
public:
	enum StateSemantic{INIT=0, SAVE_ENABLED, DELETE_ENABLED, FINAL};
	State();
	State(int entity_id, string display_name,StateSemantic state_semantic);
	void addAction(Action a);
	void addTransition(Transition t);
	void addMandatoryFields(Field f);
	void addHideFields(Field f);
	void addDenyFilds(Field f);
	Document * document;
	/*
	geteri i seteri jos
	*/

private:
	int entity_id;
	string display_name;
	list<StateSemantic> state_semantic;
	list<Action> actions;
	list<Transition> transitions;
	list<Field> mandatory_fields;
	list<Field> hide_fields;
	list<Field> deny_modyfing_filds;
};