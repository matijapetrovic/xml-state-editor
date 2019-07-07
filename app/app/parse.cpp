#pragma once

#include "parse.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Document.h"
#include "Transition.h"


int  Parser::strToInt(const char* x) {
	int y;
	stringstream s(x);
	s >> y;
	return y;
}

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


void Parser::readTransitions(string filename) {

	if (!valid_file(filename)) {
		throw InvalidFileException();
	}

	TiXmlDocument doc(filename.c_str());
	doc.LoadFile();
	TiXmlElement* root = doc.FirstChildElement();


	TiXmlElement *transition = root->FirstChildElement("Transition");

	ofstream os("f.txt");
	for (TiXmlElement* elem = transition->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		
		Transition transition;
		string elemName = elem->Value();
		const char* attr;
		if (elemName == "Connection")
		{
			attr = elem->Attribute("entityId");
			if (attr != NULL) {
				int id = strToInt(attr);
				os << id << endl;
				transition.set_entity_id(id);
			}
		}
		for (TiXmlElement* elem2 = elem->FirstChildElement(); elem2 != NULL; elem2 = elem2->NextSiblingElement()) {
			string elemName = elem2->Value();
			const char* attr;
			if (elemName == "Property")
			{
				attr = elem2->Attribute("model");
				if (attr != NULL) {
					// ako je lifecycle name naziv modela onda setujem atribut
					transition.set_lifecycle_name(attr);
					os << " " << attr;
					
				}
			}
			for (TiXmlElement* elem3 = elem2->FirstChildElement(); elem3 != NULL; elem3 = elem3->NextSiblingElement()) {
				string elemName = elem3->Value();
				const char* attr2;
				if (elemName == "Value")
				{
					attr2 = elem3->Attribute("name");
					if (attr2 != NULL) {
						os << " " << attr2;
						/* Ovde sam dobio atribute od svih property-ja*/
					}
					attr2 = elem3->Attribute("entityId");
					if (attr2 != NULL) {
						os << " " << attr2;
						/* Ovde sam dobio atribute od svih property-ja*/
					}
					for (TiXmlNode* e = elem3->FirstChild(); e != NULL; e = e->NextSibling())
					{
						TiXmlText* text = e->ToText();
						if (text == NULL)
							continue;
						string t = text->Value();
						os << "   " << t;

					}
					
					//ovde ide if u slucaju da je tekst

				}else if (elemName == "EnumValue")
				{	
					// u slucaju da sam nasisao na tekst
					for (TiXmlNode* e = elem3->FirstChild(); e != NULL; e = e->NextSibling())
					{
						TiXmlText* text = e->ToText();
						if (text == NULL)
							continue;
						string t = text->Value();
						const char* t1 = t.c_str();
						if (strcmp(attr, "ENTITY_NAME") == 0) {
							if (strcmp(t1, "AccessPermit") == 0) {
								transition.set_entity_name(EntityName::ACCESS_PERMIT);
							}
							else if (strcmp(t1, "SwitchRequest") == 0) {
								transition.set_entity_name(EntityName::SWITCH_REQUEST);
							}
							else if (strcmp(t1, "SwitchOrder") == 0) {
								transition.set_entity_name(EntityName::SWITCH_ORDER);
							}
							
						}
						
						os << " "<< t;
						
					}
				}
			
			}os << endl;

		}os << endl;
	
		document.add_transition(transition);
	}
	os.close();
}

void Parser::readStates(string filename)
{
	if (!valid_file(filename)) {
		throw InvalidFileException();
	}

	TiXmlDocument doc(filename.c_str());
	doc.LoadFile();
	TiXmlElement* root = doc.FirstChildElement();


	TiXmlElement *state = root->FirstChildElement("State");
	ofstream os("state.txt");
	//iteriramo kroz konekcije
	for (TiXmlElement* elem = state->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		State state;
		string elemName = elem->Value();

		const char* attr;
		if (elemName == "Connection") {
			attr = elem->Attribute("entityId");
			if (attr != NULL) {
				int id = strToInt(attr);
				os << id << endl;
				state.set_entity_id(id);
			}
			
		}
		//iteriramo kroz propertije
		for (TiXmlElement* elem2 = elem->FirstChildElement(); elem2 != NULL; elem2 = elem2->NextSiblingElement()) {
			string elemName = elem2->Value();
			const char* attr;
			if (elemName == "Property") {
				attr = elem2->Attribute("model");

			}
			//iteriramo kroz values/enum values
			for (TiXmlElement* elem3 = elem2->FirstChildElement(); elem3 != NULL; elem3 = elem3->NextSiblingElement()) {
				
				string elemName = elem3->Value();
				const char* attr2;
				if (elemName == "Value")
				{
					attr2 = elem3->Attribute("entityId");
					if (attr2 != NULL) {
						os << " " << attr2;
						int id = strToInt(attr2);
						state.add_transition_id(id);

					}
				}
				
				for (TiXmlNode* e = elem3->FirstChild(); e != NULL; e = e->NextSibling()) {
					TiXmlText* text = elem3->ToText();
					if (text == NULL) {
						continue;
					}
					string t = text->Value();
					const char* t1 = t.c_str();

					if (strcmp(attr, "LIFECYCLE_NAME") == 0) {
						state.set_lifecycle_name(t1);
					}
					else if (strcmp(attr, "ENTITY_NAME") == 0) {
						if (strcmp(t1, "AccessPermit") == 0) {
							state.set_entity_name(EntityName::ACCESS_PERMIT);
						}
						else if (strcmp(t1, "SwitchRequest") == 0) {
							state.set_entity_name(EntityName::SWITCH_REQUEST);
						}
						else if (strcmp(t1, "SwitchOrder") == 0) {
							state.set_entity_name(EntityName::SWITCH_ORDER);
						}

					}
					else if (strcmp(attr, "DISPLAY_NAME")) {
						state.set_display_name(t1);
					}
				}
			}

			

		}
	}
}
