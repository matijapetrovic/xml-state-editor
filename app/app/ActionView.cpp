#include "ActionView.h"
#include "globals.h"

ActionView::ActionView(Action& _model) :
	QPushButton(_model.get_label().c_str()),
	model(_model)
{
	setFixedSize(BUTTON_W, BUTTON_H);
}