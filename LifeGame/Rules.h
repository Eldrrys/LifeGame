#pragma once
#include <vector>
#include <string>

class Rules {
	std::vector<bool> borned;
	std::vector<bool> survived;
public:
	Rules();
	~Rules();
	std::string rules_to_string();
	std::vector<bool> get_borned();
	std::vector<bool> get_survived();
	void Rules::set_rules(std::vector<bool>, std::vector<bool>);
};