#include "MainView.h"
#include "DocumentView.h"

MainView::MainView() :
	main_window(new MainWindow),
	file_dialog(new FileDialog)
{
}

MainView::~MainView() {
	delete main_window;
	delete file_dialog;
}

void MainView::show() {
	if (file_dialog->exec()) {
//		main_window->setCentralWidget(new DocumentView(*file_dialog->result()));
		main_window->show();
	}
}
