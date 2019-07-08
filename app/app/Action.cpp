#include "Action.h"

using namespace std;

Action::Action()
{
}

Action::Action(string _label, Transition* trans) : label(_label), name(_label), transition(trans) {

}