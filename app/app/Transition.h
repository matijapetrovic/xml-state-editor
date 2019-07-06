#pragma once
#include <iostream>
#include <Document.h>
#include <string>
#include <State.h>

using namespace std;

class Transition {
public:
	enum EntityName { ACCESS_PERMIT = 0, SWITCH_ORDER, SWITCH_REQUEST};

	Transition();
	Transition(int entity_id, string lifecycle_name, EntityName en_name);
	Transition(int entity_id, string lifecycle_name, EntityName en_name, State on_succeed, State on_fail);
	State& on_succeed;
	State& on_fail;

private:
	int entity_id;
	string lifecycle_name;
	EntityName entity_name;
};