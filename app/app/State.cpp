#include "State.h"

using namespace std;

State::State(int _entity_id, string _display_name, Document* _document) :
	entity_id(_entity_id),
	display_name(_display_name),
	document(_document)    {}


void State::setStateSemantic(list<StateSemantic>& ss)
{
	state_semantic = ss;
}
void State::setActions(list<Action>& act)
{
	actions = act;
}
void State::setTransitions(list<Transition>& tr)
{
	transitions = tr;
}
void State::setMandatory(list<Field>& mandatory)
{
	mandatory_fields = mandatory;
}
void State::setHide(list<Field>& hide)
{
	hide_fields = hide;
}
void State::setDeny(list<Field>& deny)
{
	deny_modyfing_filds = deny;
}

void State::addAction(Action a)
{
	actions.push_back(a);
}
void State::addTransition(Transition t)
{
	transitions.push_back(t);
}
void State::addMandatoryFields(Field f)
{
	mandatory_fields.push_back(f);
}
void State::addHideFields(Field hide)
{
	hide_fields.push_back(hide);
}
void State::addDenyFilds(Field deny)
{
	deny_modyfing_filds.push_back(deny);
}
