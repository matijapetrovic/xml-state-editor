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

int Transition::getEntityId()
{
	return entity_id;
}
string Transition::getLifecycleName()
{
	return lifecycle_name;
}
EntityName Transition::getEntityName()
{
	return entity_name;
}
void Transition::setEntityId(int id)
{
	entity_id = id;
}
void Transition::setLifecycleName(string name)
{
	lifecycle_name = name;
}
void Transition::setEntityName(EntityName entity)
{
	entity_name = entity;
}
void Transition::setOnSucceed(State* onsucceed)
{
	on_succeed = onsucceed;
}
void Transition::setOnFail(State* onfail)
{
	on_fail = onfail;
}
State* Transition::getOnFail()
{
	return on_fail;
}
State* Transition::getOnSucceed()
{
	return on_succeed;
}