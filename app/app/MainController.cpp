

#include "MainController.h"

MainController::MainController(Document& _model) : model(_model) {}

MainController::~MainController() {}

bool MainController::validate_state(State * prev_state)
{
	for (Field* f : prev_state->get_mandatory_fields())
		if (f->get_text().empty())
			return false;

	return true;
}

void MainController::do_transition(Transition* transition, State* prev_state)
{
	if (validate_state(prev_state))
		model.set_current_state(transition->get_on_succeed());
	else
		model.set_current_state(transition->get_on_fail());

	delete prev_state;
}
