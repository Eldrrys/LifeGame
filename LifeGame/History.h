#pragma once
#include "Field.h"

struct history
{
	unsigned long long step;
	std::vector<unsigned> coordinate;

	const bool operator==(history&) const;
};

class History
{
	size_t step_count = 0;
	std::vector<history> changes;
	Field previous;

public:
	History();
	~History();

	void save_field(Field&);
	void load_field(Field&);
	void clean_history(Field& prototype_);
	const unsigned get_step_count() const;
	size_t const control_cycle();
};