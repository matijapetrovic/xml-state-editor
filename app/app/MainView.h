#ifndef _MAIN_VIEW_H
#define _MAIN_VIEW_H_

#include "MainWindow.h"
#include "FileDialog.h"

class MainView {

public:
	MainView();
	~MainView();

	void show();
private:
	MainWindow* main_window;
	FileDialog* file_dialog;

};

#endif // !_MAIN_VIEW_H
