
#ifndef _ACTION_H_
#define _ACTION_H_

#include <string>

#include "Transition.h"

class Transition;

class Action {
public:
	Action();
	Action(std::string _label, Transition* trans);

	std::string get_label() { return label; }
private:
	std::string name;
	std::string label;

	Transition* transition;
	
};

#endif // _ACTION_H_