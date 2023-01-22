#include "Field.h"

Field::Field()
{
	name = "Field Name";
	field.resize(FIELD_SIZE);
	for (int i = 0; i < FIELD_SIZE; i++)
		field[i].resize(FIELD_SIZE);
	rules = Rules();
}

Field::~Field()
{
}

std::vector<Cell>& Field::operator[](int x_)
{
	return field[x_];
}


const bool Field::operator==(Field& prototype_) const
{
	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			if (prototype_[i][j].alive() != field[i][j].alive())
				return false;
	return true;
}

const std::vector<Cell>& Field::operator[](int x_) const
{
	return field[x_];
}

std::string Field::get_name() {
	return name;
}

void Field::set_name(std::string field_name) {
	name = std::move(field_name);
}

void Field::set_rules(Rules new_rules) {
	rules = new_rules;
}

Rules Field::get_rules() {
	return rules;
}