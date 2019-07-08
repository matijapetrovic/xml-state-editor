#include "MainWindow.h"

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent)
{
	init_geometry();
	setWindowTitle("XML State Machine");
}

void MainWindow::init_geometry() {
	auto desktop = QApplication::desktop();
	auto dimensions = desktop->screenGeometry();
	auto w = dimensions.width();
	auto h = dimensions.height();
	
	setGeometry(2.5*w/8, h/4, 3*w/8, h/2);
}