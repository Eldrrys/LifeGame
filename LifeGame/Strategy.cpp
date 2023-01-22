#include "Strategy.h"

Strategy::Strategy(Field& f):table(f)
{
}

Strategy::~Strategy()
{
}

void Strategy::set(int x_, int y_)
{
	table[x_][y_].born();
	history.save_field(table);
}

void Strategy::clear(int x_, int y_)
{
	table[x_][y_].die();
	history.save_field(table);
}

void Strategy::reset()
{
	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			table[i][j].die();
	history.save_field(table);
}

void Strategy::step()
{
	std::vector<std::vector<int>> neighbours;
	neighbours.resize(FIELD_SIZE);
	for (int i = 0; i < FIELD_SIZE; i++)
		neighbours[i].resize(FIELD_SIZE);

	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			neighbours[i][j] = count_neighbours(i, j);

	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			if (is_borned(neighbours[i][j], table.get_rules())) table[i][j].born();
			else if (!is_survived(neighbours[i][j], table.get_rules())) table[i][j].die();
	
	history.save_field(table);
	unsigned i = history.control_cycle();
	if (i) throw (i);
}

void Strategy::back()
{
	history.load_field(table);
}

void Strategy::load(Field& prototype_)
{
	history.clean_history(prototype_);
}

const unsigned Strategy::get_step() const
{
	return history.get_step_count();
}

int Strategy::count_neighbours(int x_, int y_) const
{
	int res = 0;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (i == 0 && j == 0)
				continue;
			else if (table[(x_ + i + FIELD_SIZE) % FIELD_SIZE][(y_ + j + FIELD_SIZE) % FIELD_SIZE].alive())
				res++;

	return res;
}

Field& const Strategy::get_field()
{
	return table;
}

bool Strategy::is_borned(int neighbours, Rules rules) 
{
	return rules.get_borned()[neighbours];
}

bool Strategy::is_survived(int neighbours, Rules rules) 
{
	return rules.get_survived()[neighbours];
}