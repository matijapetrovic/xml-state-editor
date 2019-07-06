#pragma once
#include <iostream>

using namespace std;

enum FieldType{ DATE = 0, BOOL, STRING, INT};

class Field {
public:
	Field();
	Field(string _name, string _text, FieldType _type);
	void setName(string _name) { name = _name; }
	void setText(string _text) { text = _text; }
	void setType(FieldType _type) { type = _type; }
	string getName() { return name; }
	string getText() { return text; }
	FieldType getType() { return type; }
private:
	string name;
	string text;
	FieldType type;
};