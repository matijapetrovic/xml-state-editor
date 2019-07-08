#ifndef  _STATE_H_
#define  _STATE_H_

#include <list>
#include <vector>
#include "Action.h"
#include "Transition.h"
#include "Field.h"


class Transition;
class Action;


class State {
public:
	enum StateSemantic{INIT=0, SAVE_ENABLED, DELETE_ENABLED, FINAL};
	
	State() {}
	State(int id) : entity_id(id) {}
	State(int id, std::string _display_name);
	State(const State& s);
	//copy consturctor
	
	//find
	Action* find_action(std::string name);
	Transition* find_transition(int entity);

	// Add to collection
	void add_action(Action& a);
	void add_transition(Transition& t);
	void add_mandatory_field(Field& f);
	void add_hide_field(Field& f);
	void add_deny_field(Field& f);
	void add_state_semantic(StateSemantic s);
	
	// Getters
	int get_entity_id() { return entity_id; };
	std::string get_display_name() { return display_name; };
	EntityName get_entity_name() { return entity_name; };
	std::string get_lifecycle_name() { return lifecycle_name; };

	std::string get_entity_string();

	std::vector<StateSemantic>& get_state_semantic() { return state_semantic; };
	std::vector<Action>& get_actions() { return actions; };
	std::vector<Transition>& get_transitions() { return transitions; };
	std::vector<Field>& get_mandatory_fields() { return mandatory_fields; };
	std::vector<Field>& get_hide_fields() { return hide_fields; };
	std::vector<Field>& get_deny_fields() { return deny_modyfing_filds; };

	// Setters
	void set_entity_id(int _entity_id) { entity_id = _entity_id; };
	void set_display_name(std::string _display_name) { display_name = _display_name; };
	void set_lifecycle_name(std::string _lifecycle_name) { lifecycle_name = _lifecycle_name; };
	void set_entity_name(EntityName _entity_name) { entity_name = _entity_name; }

	void set_state_semantic(std::vector<StateSemantic>& ss);
	void set_actions(std::vector<Action>& act);
	void set_transitions(std::vector<Transition>& tr);
	void set_mandatory_fields(std::vector<Field>& f);
	void set_hide_fields(std::vector<Field>& hide);
	void set_deny_fields(std::vector<Field>& deny);


	Field* find_mandatory_field(std::string name);
	Field* find_hide_field(std::string name);
	Field* find_deny_field(std::string name);

private:
	int entity_id;
	std::string display_name;
	std::string lifecycle_name;
	EntityName entity_name;

	std::vector<StateSemantic> state_semantic;
	std::vector<Action> actions;
	std::vector<Transition> transitions;
	std::vector<Field> mandatory_fields;
	std::vector<Field> hide_fields;
	std::vector<Field> deny_modyfing_filds;
};


#endif //  _STATE_H_