#include <QDebug>
#include <QTextStream>
#include <QApplication>

#include "parse.h"
#include "MainView.h"
#include "MainController.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);

	FileDialog* fd = new FileDialog;
	Document* document;

	if (!fd->exec()) {
		return 0;
	}

	document = fd->result();

	MainController* controller = new MainController(*document);

	MainView main_view(document, controller);
	main_view.show();

	return a.exec();
}
