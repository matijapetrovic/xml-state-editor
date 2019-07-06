#include "Document.h"

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
void Document::setTransitions(Transitions& tran)
{
	transitions = tran;
}
void Document::setFields(Fields& fil) 
{
	fields = fil;
}
void Document::setActions(Actions& ac)
{
	actions = ac;
}
Actions& Document::getActions()
{
	return actions;
}
Transitions& Document::getTransitions()
{
	return transitions;
}
Fields& Document::getFields()
{
	return fields;
}