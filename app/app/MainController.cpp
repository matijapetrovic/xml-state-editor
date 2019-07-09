

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

void MainController::delete_fields()
{
	//model.clear_fields();
}

void MainController::do_transition(Transition* transition, State* prev_state)
{
	model.update_state_fields(prev_state);

	if (validate_state(prev_state))
		model.set_current_state(transition->get_on_succeed(), false);
	else
		model.set_current_state(transition->get_on_fail(), true);

	delete prev_state;
}
