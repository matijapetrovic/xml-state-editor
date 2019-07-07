#include "App.h"

int main(int argc, char *argv[])
{
	App a(argc, argv);
	a.show_document_dialog();
	return a.exec();
}
