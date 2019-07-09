
#ifndef _ACTION_H_
#define _ACTION_H_

#include <string>

#include "Transition.h"

class Transition;

class Action {
public:
	Action();
	Action(std::string _label);

	std::string get_label() { return label; }
	std::string get_name() { return name; }
private:
	std::string name;
	std::string label;
	
};

#endif // _ACTION_H_