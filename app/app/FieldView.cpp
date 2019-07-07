#include "FieldView.h"

FieldView::FieldView(Field & _model) : 
	QLineEdit(),
	model(_model)
{
}

FieldView::~FieldView() {

}