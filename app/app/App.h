#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_App.h"

class App : public QMainWindow
{
	Q_OBJECT

public:
	App(QWidget *parent = Q_NULLPTR);

private:
	Ui::AppClass ui;
};
