#include "Field.h"

using namespace std;

Field::Field(string _name, string _text, FieldType _type) : 
	
	name(_name), 
	text(_text),
	type(_type) {}

bool operator<(const Field & a, const Field & b)
{
	return a.get_name() < b.get_name();
}
