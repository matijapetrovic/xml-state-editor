#pragma once
#include "tinystr.h"
#include "tinyxml.h"

using namespace std;

class InvalidFileException :public std::runtime_error {
public:
	InvalidFileException() :std::runtime_error("Invalid file ! ") {}
};

class Parser {

public:

	bool valid_file(string filename);
	void read(string filename);

};