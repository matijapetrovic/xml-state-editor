#include "FileDialog.h"

FileDialog::FileDialog() :
	QDialog(),
	opened_document(nullptr)
{
	init_geometry();
	init_layout();
}

FileDialog::~FileDialog() {
	delete_layout();
}

void FileDialog::init_layout()
{
	layout = new QGridLayout();
	
	input = new QLineEdit();
	input->setEnabled(false);

	browse_button = new QPushButton("Browse");
	connect(browse_button, SIGNAL (released()), this, SLOT (browse_folders()));

	ok_button = new QPushButton("Ok");
	connect(ok_button, SIGNAL(released()), this, SLOT(accept_action()));

	cancel_button = new QPushButton("Cancel");
	connect(cancel_button, SIGNAL(released()), this, SLOT(reject()));

	layout->addWidget(new QLabel("Choose XML file:"), 0, 0, 1, 4);
	layout->addWidget(input, 1, 0, 1, 4);
	layout->addWidget(browse_button, 1, 4, 1, 1);
	layout->addWidget(new QWidget(), 2, 0, 1, 4);
	layout->addWidget(new QWidget(), 3, 0, 1, 4);
	layout->addWidget(ok_button, 4, 3, 1, 1);
	layout->addWidget(cancel_button, 4, 4, 1, 1);

	setLayout(layout);
}

void FileDialog::browse_folders() {
	QString directory = QFileDialog::getOpenFileName(this, tr("Choose File"),
		"", tr("XML documents (*.xml)"));
	
	if (directory.length() != 0)
		input->setText(directory);

}

void FileDialog::init_geometry() {
	setFixedSize(550, 140);
	auto x = frameGeometry();
	x.moveCenter(QDesktopWidget().availableGeometry().center());
	move(x.topLeft() - QPoint(0, 100));
}

void FileDialog::accept_action() {
	// ovde treba proveriti validnost xml-a
	// napraviti error box u slucaju da je lose
	// inace ucitati dokument i accept
	accept();
}

Document* FileDialog::result() {
	return opened_document;
}

void FileDialog::delete_layout() {
	delete browse_button;
	delete ok_button;
	delete cancel_button;

	delete input;
	delete layout;
}