#pragma once
#include "Strategy.h"
#include <iostream>
#include <string>

class View
{

public:
	View(){};
	View(const View&) {};

	static void print_field(Field&, const unsigned steps);
	static void print_help();
};

