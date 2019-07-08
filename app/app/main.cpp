#include <QDebug>
#include <QTextStream>
#include <QApplication>

#include "parse.h"
#include "MainView.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);

	FileDialog* fd = new FileDialog;

	Document* document;
	Parser p;
	p.read_and_connect("Lifecycle.xml");
	if (fd->exec()) {
		document = fd->result();

		MainView main_view(document);
		main_view.show();
	}


	return a.exec();
}
