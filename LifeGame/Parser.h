#pragma once
#include "Executor.h"
#include <streambuf>
#include <cctype>

class Parser
{
public:
	Parser();
	~Parser();

	std::string parser_command();
	std::string& read_file();
	std::string& write_file();
	std::string& parser_strategy_arguments(std::string&);

	bool wrong_arguments(std::string);
	bool wrong_value(std::string);
};

