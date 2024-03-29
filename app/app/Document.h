#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <string>
#include <list>
#include <set>
#include "Field.h"
#include "State.h"
#include "Transition.h"
#include <QObject>

class State;
class Transition;
class Action;

class Document : public QObject {
	Q_OBJECT

public:
	Document() {};
	Document(std::string _name);
	Document(std::string _name, State* s);
	~Document();
	
	void add_transition(Transition t);
	void add_field(Field& f);
	void add_action(Action& a);
	void add_state(State* s);
	
	void set_name(std::string _name) { name = _name; };
	void set_current_state(State * _state, bool error);
	
	void set_states(std::list<State*>& stat);
	void set_transitions(std::list<Transition>& tran);
	void set_fields(std::set<Field>& fil);
	void set_actions(std::list<Action>& ac);

	bool action_exsist(Action a);
	Action* find_action(Action a);
	Transition* corresponding_trans(Action& a);
	
	std::list<Action>& get_actions();
	std::list<Transition>& get_transitions();
	std::list<State*>& get_states();
	std::set<Field>& get_fields();
	std::string get_name() { return name; };
	State* get_current_state() { return current_state; };

	void clear_fields();
	void update_state_fields(State* prev_state);

private:
	std::string name;
	
	State* current_state;
	
	std::list<State*> states;
	std::list<Transition> transitions;
	std::set<Field> fields;
	std::list<Action> actions;

Q_SIGNALS:
	void model_updated(bool error);
};


#endif // !_DOCUMENT_H_