#ifndef _APP_H_
#define _APP_H_

#include <QApplication>
#include "MainWindow.h"
#include "Document.h"

class App : public QApplication
{
	Q_OBJECT

public:
	// Constructor
	App(int argc, char* argv[]);
	
	// Destructor
	~App();

	// API function for showing the choose document dialog
	void show_document_dialog();

	// API function for showing the main window of the application
	void show_main_window();

private:
	MainWindow* main_window;
	Document* document;
};

#endif // _APP_H_