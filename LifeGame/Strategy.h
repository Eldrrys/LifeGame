#pragma once
#include "History.h"
#include "Rules.h"

class Strategy
{
	Field& table;
	History history;
	Rules rules;

public:
	Strategy(Field &f);
	~Strategy();

	void set(int , int );
	void clear(int , int );
	void reset();

	void step();
	void back();

	void load(Field& prototype_);
	const unsigned get_step() const;
	Field& const get_field();

	int count_neighbours(int x_, int y_) const;

	bool is_borned(int, Rules);
	bool is_survived(int, Rules);
};

