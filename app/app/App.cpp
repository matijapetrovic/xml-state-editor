#include "App.h"
#include "FileDialog.h"

App::App(int argc, char* argv[]):
	QApplication(argc, argv),
	main_window(new MainWindow()),
	document(nullptr)
{
}

App::~App() {
	delete main_window;
}

void App::show_document_dialog() {
	FileDialog* fd = new FileDialog();
	if (fd->exec()) {
		document = fd->result();
		show_main_window();
	}
	delete fd;
}

void App::show_main_window()
{
	main_window->show(); 
}
