#include <QtWidgets/QApplication>
#include<QDebug>
#include <QTextStream>
#include "parse.h"
#include "App.h"

#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	
	App a(argc, argv);
	a.show_document_dialog();
	Parser p;
	p.readTransitions("Lifecycle.xml");

	return a.exec();
}
