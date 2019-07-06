#ifndef _TRANSITION_H_
#define _TRANSITION_H_

#include <string>

#include "Document.h"
#include "State.h"


enum EntityName { ACCESS_PERMIT = 0, SWITCH_ORDER, SWITCH_REQUEST };

class State;
class Document;

class Transition {
public:
	Transition();
	Transition(int entity_id, std::string lifecycle_name, EntityName en_name);
	Transition(int entity_id, std::string lifecycle_name, EntityName en_name, State* on_succeed, State* on_fail);
	

	int getEntityId();
	std::string getLifecycleName();
	EntityName getEntityName();
	void setEntityId(int id);
	void setLifecycleName(std::string name);
	void setEntityName(EntityName entity);
	void setOnSucceed(State* onsucceed);
	void setOnFail(State* onfail);
	State* getOnFail();
	State* getOnSucceed();

private:
	int entity_id;
	std::string lifecycle_name;
	EntityName entity_name;

	State* on_succeed;
	State* on_fail;
};

#endif // _TRANSITION_H_
