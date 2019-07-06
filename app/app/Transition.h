#pragma once
#include <iostream>
#include <Document.h>
#include <string>
#include <State.h>

using namespace std;

enum EntityName { ACCESS_PERMIT = 0, SWITCH_ORDER, SWITCH_REQUEST };

class Transition {
public:
	Transition();
	Transition(int entity_id, string lifecycle_name, EntityName en_name);
	Transition(int entity_id, string lifecycle_name, EntityName en_name, State on_succeed, State on_fail);
	State on_succeed;
	State on_fail;

	int getEntityId();
	string getLifecycleName();
	EntityName getEntityName();
	void setEntityId(int id);
	void setLifecycleName(string name);
	void setEntityName(EntityName entity);
	void setOnSucceed(State onsucceed);
	void setOnFail(State onfail);
	State getOnFail();
	State getOnSucceed();

private:
	int entity_id;
	string lifecycle_name;
	EntityName entity_name;
};