#include "DocumentView.h"
#include "ActionView.h"
#include <QMessageBox>

using namespace std;

DocumentView::DocumentView(Document & _model, MainController& _controller) :
	model(_model),
	controller(_controller),
	layout(new QGridLayout())
{
	connect(this, &DocumentView::action_button_pushed, &controller, &MainController::do_transition);
	connect(&model, &Document::model_updated, this, &DocumentView::handle_model_update);

	init_info_panel();
	init_transition_panel();
	init_fields_panel();
	init_buttons_panel();

	layout->addWidget(info_panel, 0, 0, 1, 1);
	layout->addWidget(transition_panel, 0, 1, 1, 1);
	layout->addWidget(fields_panel, 1, 0, 2, 4);
	layout->addWidget(buttons_panel, 2, 0, 2, 1);
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

	update_info();

	reset_transitions();
	update_transitions();
}

void DocumentView::handle_model_update(bool error)
{
	if (error)
		auto reply = QMessageBox::critical(this, tr("Transition faild."), "Mandatoty fields must be filled.", QMessageBox::Ok);

	update_view();
}

void DocumentView::init_info_panel() 
{
	info_panel = new QWidget();
	info_panel_layout = new QVBoxLayout();

	doc_type_label = new QLabel();
	doc_type_label->setStyleSheet("font-weight:bold;");
	info_panel_layout->addWidget(doc_type_label);

	info_panel_layout->setAlignment({ Qt::AlignLeft, Qt::AlignTop });

	name_label = new QLabel();
	name_label->setStyleSheet("font-weight:bold;");
	info_panel_layout->addWidget(name_label);

	info_panel->setLayout(info_panel_layout);
	
	update_info();
}

void DocumentView::init_transition_panel() 
{
	transition_panel = new QWidget();
	transition_panel_layout = new QHBoxLayout();

	transition_panel_layout->setAlignment({ Qt::AlignLeft, Qt::AlignTop });

	for (Action& action : model.get_actions()) {
		transition_buttons.push_back(new ActionView(action));
		transition_panel_layout->addWidget(transition_buttons.back());
		connect(transition_buttons.back(), SIGNAL(released()), this, SLOT(handle_action ()));
	}

	transition_panel->setLayout(transition_panel_layout);

	update_transitions();
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

void DocumentView::init_buttons_panel()
{
	buttons_panel = new QWidget();
	buttons_panel_layout = new QHBoxLayout();

	save_button = new QPushButton("Save");
	

	delete_button = new QPushButton("Delete");
	connect(delete_button, SIGNAL(released()), this, SLOT(handle_button_pushed()));

	buttons_panel->setLayout(buttons_panel_layout);
}

void DocumentView::update_info()
{
	name_label->setText(("Current state: " + model.get_current_state()->get_display_name()).c_str());
	doc_type_label->setText(("Doc type: " + model.get_current_state()->get_entity_string()).c_str());
}

void DocumentView::reset_fields()
{
	for (FieldView* fv : fields) {
		fv->setDisabled(false);
		fv->setVisible(false);
	}

	for (QLabel* l : field_labels) {
		string l_string = l->text().toStdString();
		if (l_string.find("*") != string::npos)
			l->setText(l_string.substr(0, l_string.length() - 1).c_str());
		l->setVisible(false);
	}

	for (auto i = 0; i < fields_panel_layout->rowCount(); i++)
		fields_panel_layout->takeAt(i);
}

void DocumentView::update_fields() 
{
	list<QLabel*>::const_iterator it_lab = field_labels.begin();
	for (FieldView* fv : fields) {
		if (model.get_current_state()->find_mandatory_field((*it_lab)->text().toStdString()) != nullptr) {
			string l_string = (*it_lab)->text().toStdString();
			(*it_lab)->setText((l_string + "*").c_str());
			(*it_lab)->setVisible(true);
			fv->setVisible(true);
			fields_panel_layout->addRow(*it_lab, fv);
		}
		else if (model.get_current_state()->find_deny_field((*it_lab)->text().toStdString()) != nullptr) {
			fv->setDisabled(true);
			(*it_lab)->setVisible(true);
			fv->setVisible(true);

			fields_panel_layout->addRow(*it_lab, fv);
		}
		
		it_lab++;
	}
}

void DocumentView::reset_transitions() 
{
	for (ActionView* av : transition_buttons)
		av->setVisible(false);
}

void DocumentView::update_transitions() 
{
	for (ActionView* av : transition_buttons) {
		if (model.get_current_state()->find_action(av->get_model()->get_label()) != nullptr)
			av->setVisible(true);
	}
}

void DocumentView::handle_action() 
{
	State* prev_state = new State(*model.get_current_state());

	for (Field* f : prev_state->get_mandatory_fields()) {
		for (FieldView* fv : fields) {
			if (fv->get_model().get_name() == f->get_name())
				f->set_text(fv->text().toStdString());
		}
	}

	for (Field* f : prev_state->get_deny_fields()) {
		for (FieldView* fv : fields) {
			if (fv->get_model().get_name() == f->get_name())
				f->set_text(fv->text().toStdString());
		}
	}

	for (Field* f : prev_state->get_hide_fields()) {
		for (FieldView* fv : fields) {
			if (fv->get_model().get_name() == f->get_name())
				f->set_text(fv->text().toStdString());
		}
	}

	ActionView* av = (ActionView*) sender();

	emit action_button_pushed(model.corresponding_trans(*av->get_model()), prev_state);
}

void DocumentView::handle_button_pushed() {
	emit delete_button_pushed();
}

void DocumentView::delete_info_panel() 
{
	delete info_panel;
}

void DocumentView::delete_transition_panel()
{
	for (ActionView* av : transition_buttons)
		delete av;
	delete transition_panel;
}

void DocumentView::delete_fields_panel() 
{
	for (QLabel* label : field_labels)
		delete label;
	for (FieldView* field : fields)
		delete field;
	delete fields_panel;
}

void DocumentView::delete_buttons_panel()
{
	delete save_button;
	delete delete_button;
	delete buttons_panel;

}