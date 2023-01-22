#include "Game.h"

int main(int argc, char** argv)
{
	Game<Parser, Field, Strategy, Executor, Rules> life;
	life.run_game();
	return 0;
}