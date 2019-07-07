#include "Transition.h"

using namespace std;



Transition::Transition(int _entity_id, string _lifecycle_name, EntityName _en_name)
{
	entity_id = _entity_id;
	lifecycle_name = _lifecycle_name;
	entity_name = _en_name;
}

Transition::Transition(int _entity_id, string _lifecycle_name, EntityName _en_name,State* on_succ, State* on_f) :
	entity_id(_entity_id),
	lifecycle_name(_lifecycle_name),
	entity_name(_en_name),
	on_succeed(on_succ),
	on_fail(on_f) {}

int Transition::get_entity_id()
{
	return entity_id;
}
string Transition::get_lifecycle_name()
{
	return lifecycle_name;
}
EntityName Transition::get_entity_name()
{
	return entity_name;
}
void Transition::set_entity_id(int id)
{
	entity_id = id;
}
void Transition::set_lifecycle_name(string name)
{
	lifecycle_name = name;
}
void Transition::set_entity_name(EntityName entity)
{
	entity_name = entity;
}
void Transition::set_on_succeed(State* onsucceed)
{
	on_succeed = onsucceed;
}
void Transition::set_on_fail(State* onfail)
{
	on_fail = onfail;
}
State* Transition::get_on_fail()
{
	return on_fail;
}
State* Transition::get_on_succeed()
{
	return on_succeed;
}