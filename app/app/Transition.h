#ifndef _TRANSITION_H_
#define _TRANSITION_H_

#include <string>
#include "enum.h"
#include "Document.h"
#include "State.h"

// Forward declarations
class State;
class Document;



class Transition {
public:
	Transition() {}
	Transition(int id, std::string name, EntityName entity);
	Transition(int id, std::string name, EntityName entity, State* succeed, State* fail);
	
	// Getters
	int get_entity_id();
	std::string get_lifecycle_name();
	EntityName get_entity_name();
	State* get_on_fail();
	State* get_on_succeed();
	int get_on_succeed_num();
	int get_on_failed_num();


	// Setters
	void set_entity_id(int id);
	void set_lifecycle_name(std::string name);
	void set_entity_name(EntityName entity);
	void set_on_succeed(State* succeed);
	void set_on_fail(State* fail);
	void set_on_succeed_num(int num);
	void set_on_failed_num(int num);

private:
	int entity_id;
	std::string lifecycle_name;
	EntityName entity_name;

	State* on_succeed;
	State* on_fail;

	int on_succeed_num;
	int on_failed_num;
};

#endif // _TRANSITION_H_
