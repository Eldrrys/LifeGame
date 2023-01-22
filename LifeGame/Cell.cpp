#include "Cell.h"

Cell::Cell() :state(0)
{
}

Cell::~Cell()
{
}

bool const Cell::alive() const
{
	return state;
}

void Cell::born()
{
	state = true;
}

void Cell::die()
{
	state = false;
}

char Cell::is_alive()
{
	if (state)
		return '*';
	return'.';
}