#pragma once

#include "Document.h"
#include <QObject>

class MainController : public QObject {
	Q_OBJECT

private:
	Document& model;

public:
	MainController(Document& _model);
	~MainController();

	bool validate_state(State* prev_state);

public Q_SLOTS:
	void do_transition(Transition* transition, State* prev_state);
};
