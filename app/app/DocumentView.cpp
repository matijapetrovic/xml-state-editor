#include "DocumentView.h"

DocumentView::DocumentView(Document & _model) :
	model(_model),
	layout(new QGridLayout())
{
	init_info_panel();
	init_transition_panel();
	init_fields_panel();

	layout->addWidget(info_panel, 0, 0);
	layout->addWidget(transition_panel, 0, 1);
	layout->addWidget(fields_panel, 1, 1, 1, 2);
	setLayout(layout);
}

DocumentView::~DocumentView() {
	delete_info_panel();
	delete_transition_panel();
	delete_fields_panel();
}

void DocumentView::init_info_panel() {
	info_panel = new QWidget();
	info_panel_layout = new QVBoxLayout();

	doc_type_label = new QLabel();
	name_label = new QLabel(model.get_name().c_str());
	
	info_panel_layout->addWidget(doc_type_label);
	info_panel_layout->addWidget(name_label);

	info_panel->setLayout(info_panel_layout);
	info_panel->show();
}

void DocumentView::init_transition_panel() {
	transition_panel = new QWidget();
	transition_panel_layout = new QHBoxLayout();

	for (Action& action : model.get_state()->get_actions()) {
		transition_buttons.push_back(new QPushButton(action.get_label().c_str()));
		// povezi akcije sa tranzicijama
		transition_panel_layout->addWidget(transition_buttons.back());
	}
}

void DocumentView::init_fields_panel() {
	fields_panel = new QWidget();
	fields_panel_layout = new QFormLayout();

	for (Field& field : model.get_fields()) {
		field_labels.push_back(new QLabel(field.get_name().c_str()));
		fields.push_back(new FieldView(field));
		fields_panel_layout->addRow(field_labels.back(), fields.back());
	}

	fields_panel->setLayout(fields_panel_layout);
	fields_panel->show();
}

void DocumentView::delete_info_panel() {
	delete info_panel;
	delete info_panel_layout;
	delete id_label;
	delete name_label;
	delete doc_type_label;
}

void DocumentView::delete_transition_panel() {

}

void DocumentView::delete_fields_panel() {
	for (QLabel* label : field_labels)
		delete label;
	for (FieldView* field : fields)
		delete field;
	delete fields_panel;
	delete fields_panel_layout;
}