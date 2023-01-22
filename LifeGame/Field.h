#pragma once
#include "Cell.h"
#include <vector>
#include "Rules.h"

const int FIELD_SIZE = 10;

class Field
{
	std::vector<std::vector<Cell>> field;
	std::string name;
	Rules rules;

public:

	Field();
	~Field();

	std::vector<Cell>& operator[](int);
	const std::vector<Cell>& operator[](int) const;
	const bool operator==(Field&) const;
	std::string get_name();
	void set_name(std::string);
	void set_rules(Rules);
	Rules get_rules();
};

