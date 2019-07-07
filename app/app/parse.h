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


public:
	Document document;

	int strToInt(const char*);
	bool valid_file(string filename);
	void readTransitions(string filename);
	void readStates(string filename);
	void connect();


};