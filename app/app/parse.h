#pragma once
#include "tinystr.h"
#include "tinyxml.h"
#include <string>
#include "Document.h"

using namespace std;

class InvalidFileException :public std::runtime_error {
public:
	InvalidFileException() :std::runtime_error("Invalid file ! ") {}
};

class Parser {

private:
	/*
		Set all states with appropriate transition
	*/
	void fill_states();
	
	/*
		Set all transitions with appropriate states
	*/
	void fill_transitions();

	/*
		Calls fill_states and fill_transitions
	*/
	void connect();

public:
	Document document;

	int strToInt(const char*);
	bool valid_file(string filename);
	void readTransitions(string filename);
	void readStates(string filename);
	void read_and_connect(string filename);
	



};