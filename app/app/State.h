#pragma once
#include <iostream>
#include <string>
#include <list>
#include <Action.h>
#include <Transition.h>

using namespace std;

class State {
public:
	enum StateSemantic{INIT=0, SAVE_ENABLED, DELETE_ENABLED, FINAL};
	Document * document;
	State();
	State(int entity_id, string display_name,Document* _document);
	void addAction(Action a);
	void addTransition(Transition t);
	void addMandatoryFields(Field f);
	void addHideFields(Field f);
	void addDenyFilds(Field f);
	
	void setEntityId(int _entity_id) { entity_id= _entity_id; };
	void setDisplayName(string _display_name) { display_name = _display_name; };
	int getEntityId() { return entity_id; };
	string getDisplayName() { return display_name; };
	Document* getDocument() { return document; };
	void setDocument(Document * doc) { document = doc; };

	list<StateSemantic>& getStateSemantic() { return state_semantic; };
	Actions& getActions() { return actions; };
	Transitions& getTransitions() { return transitions; };
	Fields& getMandatoryFields() { return mandatory_fields; };
	Fields& getHideFields() { return hide_fields; };
	Fields& getDenyModyfingFilds() { return deny_modyfing_filds; };

	void setStateSemantic(list<StateSemantic>& ss);
	void setActions(Actions& act);
	void setTransitions(Transitions& tr);
	void setMandatory(Fields& f);
	void setHide(Fields& hide);
	void setDeny(Fields& deny);

	/*
	geteri i seteri jos
	*/

private:
	int entity_id;
	string display_name;
	list<StateSemantic> state_semantic;
	Actions actions;
	Transitions transitions;
	Fields mandatory_fields;
	Fields hide_fields;
	Fields deny_modyfing_filds;
};