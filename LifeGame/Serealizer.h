#pragma once
#include <fstream>
#include "Field.h"
#include "Rules.h"

class Serealizer
{
	Field& field;
	Rules rules;

public:

	Serealizer(Field&);
	~Serealizer();

	void store_field(std::string&);
};

