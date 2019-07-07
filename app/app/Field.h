#ifndef _FIELD_H_
#define _FIELD_H_

#include <string>

enum FieldType{ DATE = 0, BOOL, STRING, INT};

class Field {
public:
	Field() {}
	Field(std::string _name, std::string _text, FieldType _type);

	void set_name(std::string _name) { name = _name; }
	void set_text(std::string _text) { text = _text; }
	void set_type(FieldType _type) { type = _type; }
	
	std::string get_name() { return name; }
	std::string get_text() { return text; }
	FieldType get_type() { return type; }

private:
	std::string name;
	std::string text;
	FieldType type;
};

#endif // _FIELD_H_