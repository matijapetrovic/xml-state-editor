#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QtWidgets/QMainWindow>
#include <QDesktopWidget>
#include <QApplication>

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget *parent = Q_NULLPTR);
private:
	void init_geometry();
};



#endif // !_MAIN_WINDOW_H_

