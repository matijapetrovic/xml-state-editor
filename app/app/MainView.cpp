#include "MainView.h"
#include "DocumentView.h"

MainView::MainView(Document* doc) :
	MainWindow(),
	document(doc)
{
	setCentralWidget(new DocumentView(*document));

}

MainView::~MainView() {
	delete document;
}

