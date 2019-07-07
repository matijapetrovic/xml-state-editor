#include "App.h"
#include "FileDialog.h"

App::App(int argc, char* argv[]):
	QApplication(argc, argv),
	document(nullptr)
{
}

App::~App() {
}
