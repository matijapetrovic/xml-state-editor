#include "DocumentView.h"
#include "ActionView.h"

using namespace std;

DocumentView::DocumentView(Document & _model) :
	model(_model),
	layout(new QGridLayout())
{
	init_info_panel();
	init_transition_panel();
	init_fields_panel();

	layout->addWidget(info_panel, 0, 0, 1, 1);
	layout->addWidget(transition_panel, 0, 1, 1, 1);
	layout->addWidget(fields_panel, 1, 1, 2, 2);
	setLayout(layout);

	update_view();
}

DocumentView::~DocumentView()
{
	delete_info_panel();
	delete_transition_panel();
	delete_fields_panel();
}

void DocumentView::update_view()
{
	reset_fields();
	update_fields();
}

void DocumentView::init_info_panel() 
{
	info_panel = new QWidget();
	info_panel_layout = new QVBoxLayout();

	doc_type_label = new QLabel(("Doc type: " + model.get_current_state()->get_entity_string()).c_str());
	doc_type_label->setStyleSheet("font-weight:bold;");
	info_panel_layout->addWidget(doc_type_label);

	name_label = new QLabel(("Current state: " + model.get_current_state()->get_display_name()).c_str());
	name_label->setStyleSheet("font-weight:bold;");
	info_panel_layout->addWidget(name_label);

	info_panel_layout->addStretch();

	info_panel->setLayout(info_panel_layout);
}

void DocumentView::init_transition_panel() 
{
	transition_panel = new QWidget();
	transition_panel_layout = new QHBoxLayout();

	for (Action& action : model.get_current_state()->get_actions()) {
		transition_buttons.push_back(new ActionView(action));
		// povezi akcije sa tranzicijama
		transition_panel_layout->addWidget(transition_buttons.back());
		connect(transition_buttons.back(), SIGNAL(released()), this, SLOT(handle_button_pushed ()));
	}

	transition_panel_layout->addStretch();

	transition_panel->setLayout(transition_panel_layout);
}

void DocumentView::init_fields_panel() 
{
	fields_panel = new QWidget();
	fields_panel_layout = new QFormLayout();

	for (const Field& field : model.get_fields()) {
		field_labels.push_back(new QLabel(field.get_name().c_str()));
		fields.push_back(new FieldView(field));
	}

	fields_panel->setLayout(fields_panel_layout);
}


void DocumentView::reset_fields()
{
	for (FieldView* fv : fields) {
		fv->setDisabled(false);
	}

	for (QLabel* l : field_labels) {
		string l_string = l->text().toStdString();
		if (l_string.find("*") != string::npos)
			l->setText(l_string.substr(0, l_string.length() - 1).c_str());
	}

	for (auto i = 0; i < fields_panel_layout->rowCount(); i++)
		fields_panel_layout->takeRow(i);
}

void DocumentView::update_fields() 
{
	list<QLabel*>::const_iterator it_lab = field_labels.begin();
	for (FieldView* fv : fields) {

		if (model.get_current_state()->find_mandatory_field((*it_lab)->text().toStdString()) != nullptr) {
			string l_string = (*it_lab)->text().toStdString();
			(*it_lab)->setText((l_string + "*").c_str());
			fields_panel_layout->addRow(*it_lab, fv);
		}
		else if (model.get_current_state()->find_deny_field((*it_lab)->text().toStdString()) != nullptr) {
			fv->setDisabled(true);
			fields_panel_layout->addRow(*it_lab, fv);
		}
		
		it_lab++;
	}
}

void DocumentView::handle_button_pushed() 
{
	State* prev_state = new State(*model.get_current_state());

	for (Field& f : prev_state->get_mandatory_fields()) {
		for (FieldView* fv : fields) {
			if (fv->get_model().get_name() == f.get_name())
				f.set_text(fv->text().toStdString());
		}
	}

	for (Field& f : prev_state->get_deny_fields()) {
		for (FieldView* fv : fields) {
			if (fv->get_model().get_name() == f.get_name())
				f.set_text(fv->text().toStdString());
		}
	}

	for (Field& f : prev_state->get_hide_fields()) {
		for (FieldView* fv : fields) {
			if (fv->get_model().get_name() == f.get_name())
				f.set_text(fv->text().toStdString());
		}
	}

	emit action_button_pushed(prev_state);
}

void DocumentView::delete_info_panel() 
{
	delete info_panel;
	delete id_label;
	delete name_label;
	delete doc_type_label;
}

void DocumentView::delete_transition_panel()
{

}

void DocumentView::delete_fields_panel() 
{
	for (QLabel* label : field_labels)
		delete label;
	for (FieldView* field : fields)
		delete field;
	delete fields_panel;
	delete fields_panel_layout;
}