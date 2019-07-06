#include "Document.h"

using namespace std;

Document::Document(string name) :
	name(name)
{}

Document::Document(string name, State* s) :
	name(name),
	state(s){}

void Document::addTransition(Transition t)
{
	transitions.push_back(t);
}
void Document::addField(Field f)
{
	fields.push_back(f);
}
void Document::addAction(Action a)
{
	actions.push_back(a);
}
void Document::setTransitions(list<Transition> &tran)
{
	transitions = tran;
}
void Document::setFields(list<Field>& fil)
{
	fields = fil;
}
void Document::setActions(list<Action>& ac)
{
	actions = ac;
}
list<Action>& Document::getActions()
{
	return actions;
}
list<Transition>& Document::getTransitions()
{
	return transitions;
}
list<Field>& Document::getFields()
{
	return fields;
}