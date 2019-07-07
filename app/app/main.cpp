#include <QtWidgets/QApplication>
#include<QDebug>
#include <QTextStream>
#include "parse.h"
#include "App.h"
#include "MainView.h"

#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	
	App a(argc, argv);

	MainView main_view;
	main_view.show();

	return a.exec();
}
