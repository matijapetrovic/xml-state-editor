#include "MainView.h"
#include "DocumentView.h"


MainView::MainView(Document* doc, MainController* ctrl) :
	MainWindow(),
	document(doc),
	controller(ctrl)
{
	setCentralWidget(new DocumentView(*document, *controller));

}

MainView::~MainView() {
}

