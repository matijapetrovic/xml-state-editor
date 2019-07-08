#ifndef _TRANSITION_H_
#define _TRANSITION_H_

#include "enum.h"
#include "Document.h"
#include "State.h"

// Forward declarations
class State;
class Document;

class Transition {
public:
	Transition() {}
	Transition(int id): entity_id(id) {}
	Transition(int id, std::string name, EntityName entity);
	Transition(int id, std::string name, EntityName entity, State* succeed, State* fail);
	Transition(const Transition& t);
	~Transition() {}
	
	// Getters
	int get_entity_id();
	std::string get_lifecycle_name();
	EntityName get_entity_name();
	State* get_on_fail();
	State* get_on_succeed();



	// Setters
	void set_entity_id(int id);
	void set_lifecycle_name(std::string name);
	void set_entity_name(EntityName entity);
	void set_on_succeed(State* succeed);
	void set_on_fail(State* fail);


private:
	int entity_id;
	std::string lifecycle_name;
	EntityName entity_name;

	State* on_succeed;
	State* on_fail;
};

#endif //_TRANSITION_H_
