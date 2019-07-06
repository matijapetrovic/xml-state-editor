#pragma once
#include <iostream>

using namespace std;

enum FieldType{ DATE = 0, BOOL, STRING, INT};

class Field {
public:
	Field();
	Field(string name, string text, FieldType field_type);
private:
	string name;
	string text;
	FieldType type;
};