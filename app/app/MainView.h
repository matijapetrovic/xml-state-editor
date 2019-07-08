#ifndef _MAIN_VIEW_H
#define _MAIN_VIEW_H_

#include "MainWindow.h"
#include "MainController.h"
#include "FileDialog.h"

class MainView : public MainWindow {

public:
	MainView(Document* document, MainController* controller);
	~MainView();
private:
	Document* document;
	MainController* controller;
	
};

#endif // !_MAIN_VIEW_H
