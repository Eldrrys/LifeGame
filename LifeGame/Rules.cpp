#include "Rules.h"

Rules::Rules() 
{
	borned = { false, false, false, true, false,  false,  false,  false,  false };
	survived = { false, false, true, true, false,  false,  false,  false,  false };
}

Rules::~Rules() 
{
}

std::vector<bool> Rules::get_borned() 
{
	return borned;
}

std::vector<bool> Rules::get_survived() {
	return survived;
}

std::string Rules::rules_to_string() 
{
	std::string borned_str = "B";
	for (int i = 0; i < 9; i++) {
		if (borned[i]) borned_str += i + '0';
	}
	std::string survived_str = "S";
	for (int i = 0; i < 9; i++) {
		if (survived[i]) survived_str += i + '0';
	}
	return borned_str + "/" + survived_str;
}

void Rules::set_rules(std::vector<bool> new_borned, std::vector<bool> new_survived) {
	borned = new_borned;
	survived = new_survived;
}