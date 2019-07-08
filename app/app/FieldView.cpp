#include "FieldView.h"

FieldView::FieldView(const Field & _model) : 
	QLineEdit(),
	model(_model)
{
}

FieldView::~FieldView() {

}