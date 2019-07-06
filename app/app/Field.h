#ifndef _FIELD_H_
#define _FIELD_H_

#include <string>

enum FieldType{ DATE = 0, BOOL, STRING, INT};

class Field {
public:
	Field() {}
	Field(std::string _name, std::string _text, FieldType _type);

	void setName(std::string _name) { name = _name; }
	void setText(std::string _text) { text = _text; }
	void setType(FieldType _type) { type = _type; }
	
	std::string getName() { return name; }
	std::string getText() { return text; }
	FieldType getType() { return type; }

private:
	std::string name;
	std::string text;
	FieldType type;
};

#endif // _FIELD_H_