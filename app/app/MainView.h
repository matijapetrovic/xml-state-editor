#ifndef _MAIN_VIEW_H
#define _MAIN_VIEW_H_

#include "MainWindow.h"
#include "FileDialog.h"

class MainView : public MainWindow {

public:
	MainView(Document* document);
	~MainView();
private:
	Document* document;
	
};

#endif // !_MAIN_VIEW_H
