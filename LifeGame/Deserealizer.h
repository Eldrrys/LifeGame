#pragma once
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include "Field.h"
#include "Rules.h"

class Deserealizer
{
public:

	Deserealizer();
	~Deserealizer();

	Field& load_field(std::istream& filename);
	Rules load_rules(std::istream& filename);
	std::string load_name(std::istream& filename);
	bool is_valid_coordinates(std::string input);
	bool is_valid_name(std::string input);
	bool is_valid_rules(std::string input);
};

