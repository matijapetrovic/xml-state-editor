#include "MainView.h"
#include "DocumentView.h"

MainView::MainView(Document* doc) :
	MainWindow(),
	document(doc)
{
	//		main_window->setCentralWidget(new DocumentView(document));

}

MainView::~MainView() {
	delete document;
}

void MainView::show() {

}
