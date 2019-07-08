#ifndef _ACTION_VIEW_H_
#define _ACTION_VIEW_H_

#include <QPushButton>

#include "Action.h"

class ActionView : public QPushButton {
	Q_OBJECT

public: 
	ActionView(Action& _model);

	Action* get_model() { return &model; }
private:

	Action& model;
};

#endif // !_ACTION_VIEW_H_
