#ifndef _APP_H_
#define _APP_H_

#include <QApplication>
#include "MainWindow.h"
#include "Document.h"
#include "DocumentView.h"

class App : public QApplication
{
	Q_OBJECT

public:
	// Constructor
	App(int argc, char* argv[]);
	
	// Destructor
	~App();


private:
	Document* document;

};

#endif // _APP_H_