#include "History.h"

History::History()
{
	changes.resize(1);
}

History::~History()
{
}

const unsigned History::get_step_count() const
{
	return step_count;
}

void History::save_field(Field& prototype_)
{
	int k = 0;
	if (previous == prototype_ && step_count)
		throw "The last configuration coincides with the previous one. The end of the game";
	step_count++;
	changes.resize(changes.size() + 1);
	changes[changes.size()-1].step = step_count;
	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			if(previous[i][j].alive() != prototype_[i][j].alive())
		{
				changes[changes.size() - 1].coordinate.resize(k + 1);
				changes[changes.size() - 1].coordinate[k++] = i * 10 + j;
		}
	previous = prototype_;
}

void History::load_field(Field& prototype_)
{
	if (!step_count || step_count != changes[changes.size() - 1].step)
		return;
	step_count--;
	for (int i = 0; i < changes[changes.size() - 1].coordinate.size(); i++)
		if (prototype_[changes[changes.size() - 1].coordinate[i] / 10][changes[changes.size() - 1].coordinate[i] % 10].alive())
			prototype_[changes[changes.size() - 1].coordinate[i] / 10][changes[changes.size() - 1].coordinate[i] % 10].die();
		else
			prototype_[changes[changes.size() - 1].coordinate[i] / 10][changes[changes.size() - 1].coordinate[i] % 10].born();
	changes.resize(changes.size() - 1);
	previous = prototype_;
}


void History::clean_history(Field& prototype_)
{
	previous = prototype_;
	step_count = 0;
	changes.resize(0);
}

size_t const History::control_cycle()
{
	if (changes.size())
	{
		for (unsigned i = 0; i < (changes.size() - 1); i++)
		{
			if (changes[i] == changes[changes.size() - 1])
				return changes[i].step;
		}
	}
	return 0;
}

const bool history::operator==(history& prototype_) const
{
	if (coordinate.size() != prototype_.coordinate.size())
		return false;
	for (int i = 0; i < coordinate.size(); i++)
		if (coordinate[i] != prototype_.coordinate[i])
			return false;
	return true;
}