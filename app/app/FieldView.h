#ifndef _FIELD_VIEW_H_
#define _FIELD_VIEW_H_

#include <QLineEdit>
#include <QLabel>

#include "Field.h"

class FieldView : public QLineEdit {
public:
	FieldView(Field& _model);
	~FieldView();

private:
	Field& model;

};


#endif // _FIELD_VIEW_H_