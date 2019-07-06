#pragma once

#include "parse.h"
#include <iostream>

/*
	Validating  file

*/
bool  Parser::valid_file(string filename) {

	TiXmlDocument doc(filename.c_str());
	bool loadOkay = doc.LoadFile();
	if (loadOkay)
	{
		return true;
	}
	return false;

}

void Parser::read(string filename) {

	if (!valid_file(filename)) {
		throw InvalidFileException();
	}

	TiXmlDocument doc(filename.c_str());
	doc.LoadFile();

	TiXmlElement* root = doc.FirstChildElement();

	TiXmlElement *transition = root->FirstChildElement("Transition");

	int n = 0;
	for (TiXmlElement* elem = transition->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		const char* attr;
		if (elemName == "Property")
		{
			attr = elem->Attribute("model");
			if (attr != NULL) {
				cout << attr << endl;
			}

		}
		n++;

	}
	cout << n;


}