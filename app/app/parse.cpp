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
					/*
						Setting lifecycle name
					
					*/
				
				}
			}
			for (TiXmlElement* elem3 = elem2->FirstChildElement(); elem3 != NULL; elem3 = elem3->NextSiblingElement()) {
				string elemName = elem3->Value();
				const char* attr2;
				if (elemName == "Value")
				{
					attr2 = elem3->Attribute("name");
					if (attr2 != NULL) {
						/*
							Ako mi bude trebala informacija da tranzicija
							sadrzi ,,STATE"
						
						*/
						
					}
					attr2 = elem3->Attribute("entityId");
					if (attr2 != NULL) {
						//ovde postavljam onsucceed i onfailed int
						State* s = new State(strToInt(attr2));
						if (strcmp(attr, "TRANSITION_ON_SUCCEED")== 0) {
							
							//transition.set_on_succeed_num(strToInt(attr2));
							transition.set_on_succeed(s);
						}
						else if (strcmp(attr, "TRANSITION_ON_FAIL")== 0) {
							//transition.set_on_failed_num(strToInt(attr2));
							transition.set_on_fail(s);
						}
					}
					// prolazim kroz sve ispise ukliko value ima samo tekst atribut
					for (TiXmlNode* e = elem3->FirstChild(); e != NULL; e = e->NextSibling())
					{
						TiXmlText* text = e->ToText();
						if (text == NULL)
							continue;
						string t = text->Value();
						if (strcmp(attr, "LIFECYCLE_NAME") == 0) {
							transition.set_lifecycle_name(t);
						}

					}
					
				

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
					}
				}
			}
		}
	
		document->add_transition(transition);
	}
	
}

void Parser::readStates(string filename)
{
	if (!valid_file(filename)) {
		throw InvalidFileException();
	}
	bool valid = false;
	bool initFound = false;
	TiXmlDocument doc(filename.c_str());
	doc.LoadFile();
	TiXmlElement* root = doc.FirstChildElement();


	TiXmlElement *stateXml = root->FirstChildElement("State");
	ofstream os("state.txt");
	//iteriramo kroz konekcije
	for (TiXmlElement* elem = stateXml->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		State* state = new State;
		string elemName = elem->Value();

		const char* attr;
		if (elemName == "Connection") {
			attr = elem->Attribute("entityId");
			if (attr != NULL) {
				int id = strToInt(attr);
				os << id << endl;
				state->set_entity_id(id);
			}

		}
		//iteriramo kroz propertije
		for (TiXmlElement* elem2 = elem->FirstChildElement(); elem2 != NULL; elem2 = elem2->NextSiblingElement()) {
			string elemName = elem2->Value();
			const char* attr;
			if (elemName == "Property") {
				attr = elem2->Attribute("model");
				os << " " << attr;

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
						Transition* t = new Transition(id);
						//state.add_transition_id(id);
						state->add_transition(t);
					}
				}

				for (TiXmlNode* e = elem3->FirstChild(); e != NULL; e = e->NextSibling()) {
					TiXmlText* text = e->ToText();
					if (text == NULL) {
						continue;
					}
					string t = text->Value();
					const char* t1 = t.c_str();
					os << " " << t;

					if (strcmp(attr, "LIFECYCLE_NAME") == 0) {
						state->set_lifecycle_name(t1);
					}
					else if (strcmp(attr, "STATE_DENY_MODIFYING_FIELDS") == 0) {

						Field* field = new Field;
						field->set_name(t);
						state->add_deny_field(field);
						document->add_field(*field);
					}
					else if (strcmp(attr, "STATE_HIDE_FIELDS") == 0) {
						Field* field = new Field;
						field->set_name(t);
						state->add_hide_field(field);
						document->add_field(*field);
					}
					else if (strcmp(attr, "STATE_MANDATORY_FIELDS") == 0) {
						Field* field = new Field;
						field->set_name(t);
						state->add_mandatory_field(field);
						document->add_field(*field);
					}
					else if (strcmp(attr, "ENTITY_NAME") == 0) {
						if (strcmp(t1, "AccessPermit") == 0) {
							state->set_entity_name(EntityName::ACCESS_PERMIT);
						}
						else if (strcmp(t1, "SwitchRequest") == 0) {
							state->set_entity_name(EntityName::SWITCH_REQUEST);
						}
						else if (strcmp(t1, "SwitchOrder") == 0) {
							state->set_entity_name(EntityName::SWITCH_ORDER);
						}

					}
					else if (strcmp(attr, "DISPLAY_NAME") == 0) {
						state->set_display_name(t1);
					}
					else if (strcmp(attr, "STATE_SEMANTIC") == 0) {
						if (strcmp(t1, "Init") == 0) {
							valid = true;
							initFound = true;
							state->add_state_semantic(State::StateSemantic::INIT);
						}
						else if (strcmp(t1, "SaveEnabled") == 0) {
							state->add_state_semantic(State::StateSemantic::SAVE_ENABLED);
						}
						else if (strcmp(t1, "DeleteEnabled") == 0) {
							state->add_state_semantic(State::StateSemantic::DELETE_ENABLED);
						}
						else if (strcmp(t1, "Final") == 0) {
							state->add_state_semantic(State::StateSemantic::FINAL);
						}
					}

				}

			}

			os << endl;

		}
		document->add_state(state);
		if (initFound) {
			document->set_current_state(document->get_states().back(), false);
			initFound = false;
		}
	}
	os.close();
	if (!valid) {
		throw MissingInitStateException();
	}
}


void Parser::fill_states() {

	for (State* state : document->get_states())
	{
		vector<Transition*>& tr = state->get_transitions();
		for (auto& t : document->get_transitions()) {
			for (int i = 0; i < tr.size(); i++) {
				if (tr[i]->get_entity_id() == t.get_entity_id()) {
					state->get_transitions()[i] = &t;
					break;
				}
			}
		}
	}


}

void Parser::fill_transitions() {

	for (Transition& trans : document->get_transitions())
	{
		for (State* state : document->get_states())
		{
			if (state->get_entity_id() == trans.get_on_succeed()->get_entity_id()) {
				delete trans.get_on_succeed();
				trans.set_on_succeed(state);

			}
			else if (state->get_entity_id() == trans.get_on_fail()->get_entity_id()) {
				delete trans.get_on_fail();
				trans.set_on_fail(state);
			}

		}
	}

}

void Parser::fill_actions()
{
	for (State* state : document->get_states()) {
		for (Transition* transition : state->get_transitions()) {
			string name = (*transition->get_on_succeed()).get_lifecycle_name();
			Action* action = new Action(name);
			if (!document->action_exsist(*action))
				document->add_action(*action);

			transition->set_action(action);
			state->add_action(action);
		}
	}
}

void Parser::connect() {
	
	
	fill_transitions();
	fill_states();
	fill_actions();
	
	
}

Document* Parser::read_and_connect(string filename) {

	readTransitions(filename);
	readStates(filename);
	connect();
	return document;
}

