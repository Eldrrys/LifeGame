#pragma once
#include "Parser.h"

template <class Parser, class Field, class Strategy, class Executor, class Rules> class Game
{
	Parser p;
	Executor e;
	Field f;
	Strategy s;
	Rules r;

public:

	Game();
	~Game();

	void run_game();
};

template<class Parser, class Field, class Strategy, class Executor, class Rules> Game<Parser, Field, Strategy, Executor, Rules>::Game() 
	:s(f), e(f, r)
{
}

template<class Parser, class Field, class Strategy, class Executor, class Rules> Game<Parser, Field, Strategy, Executor, Rules>::~Game()
{
}

template<class Parser, class Field, class Strategy, class Executor, class Rules> void Game<Parser, Field, Strategy, Executor, Rules>::run_game()
{
	View::print_help();
	View::print_field(f, s.get_step());
	while (e.call_command(p.parser_command(), s))
	{
		View::print_field(f, s.get_step());
	}

	return;
}