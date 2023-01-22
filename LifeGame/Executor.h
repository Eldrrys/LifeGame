#pragma once
#include "Deserealizer.h"
#include "Serealizer.h"
#include "View.h"
#include "Strategy.h"
#include "Rules.h"

class Executor
{
	Field& field;
	Rules& rules;
	Serealizer ser;
	Deserealizer des;

public:

	Executor(Field&, Rules&);
	~Executor();

	void strategy_executor(Strategy& , std::string );
	void call_step_or_back(Strategy&, std::string );
	void serealizer_executor(std::string& );
	void deserealizer_executor(std::string& );
	bool call_command(std::string, Strategy&);
};

