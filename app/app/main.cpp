#include "App.h"
#include <QtWidgets/QApplication>
#include<QDebug>
#include <QTextStream>
#include "parse.h"

#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	App w;
	w.show();
	Parser p;
	p.readTransitions("Lifecycle.xml");

	return a.exec();
}
