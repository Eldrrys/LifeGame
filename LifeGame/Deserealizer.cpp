#include "Deserealizer.h"
#include <regex>
Deserealizer::Deserealizer()
{
}

Deserealizer::~Deserealizer()
{
}

std::string Deserealizer::load_name(std::istream& filename) 
{
	std::string input;
	std::getline(filename, input);
	if (!is_valid_name(input))
		throw std::invalid_argument("Name format must be \"#N Field Name\"\n");
	return input.substr(3);
}

Rules Deserealizer::load_rules(std::istream& filename)
{
	std::string input;
	static Rules rules;
	std::vector<bool> borned = { false, false, false, false, false,  false,  false,  false,  false };
	std::vector<bool> survived = { false, false, false, false, false,  false,  false,  false,  false };
	std::getline(filename, input);
	if (!is_valid_rules(input))
		throw std::invalid_argument("Rules format must be \"#R Bx/Sy\" where x and y are sequences of different digits from the set {0...8}\n");
	input = input.substr(4);
	int index = input.find('/');
	for (int i = 0; i < index; i++) 
	{
		borned[input[i] - '0'] = true;
	}
	for (int i = index + 2; i < input.size(); i++)
	{
		survived[input[i] - '0'] = true;
	}
	rules.set_rules(borned, survived);
	return rules;
}

Field& Deserealizer::load_field(std::istream& filename)
{
	std::string input;
	static Field field;


	while (std::getline(filename, input))
	{
		if (!is_valid_coordinates(input))
			throw std::invalid_argument("Coordinates format must be \"x y\" where x and y are from the set {0...9}\n");
		field[input[0] - '0'][input[2] - '0'].born();
			
	}
	return field;
}

bool Deserealizer::is_valid_coordinates(std::string input)
{
	if (input.size() != 3)
		return false;
	static const std::regex r(R"(^\d{1}\s\d{1}$)");
	return std::regex_match(input, r);
}

bool Deserealizer::is_valid_name(std::string input) {
	if (input.size() < 4) return false;
	static const std::regex r(R"(^#N\s[0-9a-zA-Z\.]+)");
	return std::regex_match(input, r);
}

bool Deserealizer::is_valid_rules(std::string input) {
	if (input.size() < 8) return false;
	static const std::regex r(R"(^#R\sB[0-8]{1,9}\/S[0-8]{1,9}$)");
	return std::regex_match(input, r);
}