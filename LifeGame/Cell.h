#pragma once
#include <stdexcept>

class Cell
{
	bool state = 0;

public:

	Cell();
	~Cell();

	char is_alive();
	void born();
	void die();
	bool const alive() const;

};

