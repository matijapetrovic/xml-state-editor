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
	
	setGeometry(w/4, h/4, w/2, h/2);
}