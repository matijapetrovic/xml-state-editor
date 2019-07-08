#ifndef _DOCUMENT_VIEW_H_
#define _DOCUMENT_VIEW_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>

#include "Document.h"
#include "FieldView.h"
#include "MainController.h"

class DocumentView : public QWidget {
	Q_OBJECT

public:
	DocumentView(Document& _model, MainController& _controller);
	~DocumentView();

	void update_view();

Q_SIGNALS:
	void action_button_pushed(Transition* transition, State* prev_state);

private Q_SLOTS:
	void handle_button_pushed();

private:
	Document& model;
	MainController& controller;

	QGridLayout* layout;

	// Info panel
	QWidget* info_panel;
	QVBoxLayout* info_panel_layout;

	QLabel* id_label;
	QLabel* name_label;
	QLabel* doc_type_label;

	// Transition panel
	QWidget* transition_panel;
	QHBoxLayout* transition_panel_layout;

	std::list<QPushButton*> transition_buttons;

	// Fields panel
	QWidget* fields_panel;
	QFormLayout* fields_panel_layout;

	std::list<QLabel*> field_labels;
	std::list<FieldView*> fields;

	// Panel init helpers
	void init_info_panel();
	void init_transition_panel();
	void init_fields_panel();

	// Panel delete helpers
	void delete_info_panel();
	void delete_transition_panel();
	void delete_fields_panel();

	void reset_fields();
	void update_fields();

};


#endif // !_DOCUMENT_VIEW_H_
