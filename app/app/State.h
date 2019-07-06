#ifndef  _STATE_H_
#define  _STATE_H_

#include <string>
#include <list>

#include "Action.h"
#include "Transition.h"
#include "Document.h"
#include "Field.h"


class Transition;
class Document;

class State {
public:
	enum StateSemantic{INIT=0, SAVE_ENABLED, DELETE_ENABLED, FINAL};
	
	State();
	State(int entity_id, std::string display_name,Document* _document);
	void addAction(Action a);
	void addTransition(Transition t);
	void addMandatoryFields(Field f);
	void addHideFields(Field f);
	void addDenyFilds(Field f);
	
	void setEntityId(int _entity_id) { entity_id= _entity_id; };
	void setDisplayName(std::string _display_name) { display_name = _display_name; };
	int getEntityId() { return entity_id; };
	std::string getDisplayName() { return display_name; };
	Document* getDocument() { return document; };
	void setDocument(Document * doc) { document = doc; };

	std::list<StateSemantic>& getStateSemantic() { return state_semantic; };
	std::list<Action>& getActions() { return actions; };
	std::list<Transition>& getTransitions() { return transitions; };
	std::list<Field>& getMandatoryFields() { return mandatory_fields; };
	std::list<Field>& getHideFields() { return hide_fields; };
	std::list<Field>& getDenyModyfingFilds() { return deny_modyfing_filds; };

	void setStateSemantic(std::list<StateSemantic>& ss);
	void setActions(std::list<Action>& act);
	void setTransitions(std::list<Transition>& tr);
	void setMandatory(std::list<Field>& f);
	void setHide(std::list<Field>& hide);
	void setDeny(std::list<Field>& deny);

	/*
	geteri i seteri jos
	*/

private:
	int entity_id;
	std::string display_name;
	
	Document* document;
	
	std::list<StateSemantic> state_semantic;
	std::list<Action> actions;
	std::list<Transition> transitions;
	std::list<Field> mandatory_fields;
	std::list<Field> hide_fields;
	std::list<Field> deny_modyfing_filds;
};


#endif //  _STATE_H_