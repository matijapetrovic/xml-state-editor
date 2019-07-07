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
	
	State() {}
	State(int id, std::string _display_name, Document* _document);
	
	// Add to collection
	void add_action(Action& a);
	void add_transition(Transition& t);
	void add_mandatory_field(Field& f);
	void add_hide_field(Field& f);
	void add_deny_field(Field& f);
	
	// Getters
	int get_entity_id() { return entity_id; };
	std::string get_display_name() { return display_name; };
	EntityName get_entity_name() { return entity_name; }
	Document* get_document() { return document; };

	std::list<StateSemantic>& get_state_semantic() { return state_semantic; };
	std::list<Action>& get_actions() { return actions; };
	std::list<Transition>& get_transitions() { return transitions; };
	std::list<Field>& get_mandatory_fields() { return mandatory_fields; };
	std::list<Field>& get_hide_fields() { return hide_fields; };
	std::list<Field>& get_deny_fields() { return deny_modyfing_filds; };
	std::list<int>& get_transitions_ids() { return transitons_ids; };

	// Setters
	void set_entity_id(int _entity_id) { entity_id = _entity_id; };
	void set_display_name(std::string _display_name) { display_name = _display_name; };
	void set_entity_name(EntityName _entity_name) { entity_name = _entity_name; }
	void set_document(Document * doc) { document = doc; };

	void set_state_semantic(std::list<StateSemantic>& ss);
	void set_actions(std::list<Action>& act);
	void set_transitions(std::list<Transition>& tr);
	void set_mandatory_fields(std::list<Field>& f);
	void set_hide_fields(std::list<Field>& hide);
	void set_deny_fields(std::list<Field>& deny);


private:
	int entity_id;
	std::string display_name;
	EntityName entity_name;
	
	Document* document;
	
	std::list<int> transitons_ids;
	std::list<StateSemantic> state_semantic;
	std::list<Action> actions;
	std::list<Transition> transitions;
	std::list<Field> mandatory_fields;
	std::list<Field> hide_fields;
	std::list<Field> deny_modyfing_filds;
};


#endif //  _STATE_H_