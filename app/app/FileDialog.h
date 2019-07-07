#ifndef _FILE_DIALOG_H_
#define _FILE_DIALOG_H_

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QDesktopWidget>

#include "Document.h"

class FileDialog : public QDialog {
	Q_OBJECT

public:
	FileDialog();
	~FileDialog();

	Document* result();

public slots:
	void browse_folders();
	void accept_action();

private:

	QGridLayout* layout;
	QLineEdit* input;

	QPushButton* browse_button;
	QPushButton* ok_button;
	QPushButton* cancel_button;

	Document* opened_document;

	void init_layout();
	void init_geometry();

	void delete_layout();
};

#endif // _FILE_DIALOG_H_
