#include "View.h"

void View::print_help()
{
	std::cout << "HELP" << std::endl;
	std::cout << "1. For saving game  into file <filename> enter \"save <filename>\"" << std::endl;
	std::cout << "2. For loading game from file <filename> enter \"load <filename>\"" << std::endl;
	std::cout << "3. For N iterations enter \"step <N>\"" << std::endl;
	std::cout << "4. For step back enter \" back \"" << std::endl;
	std::cout << "5. For reset field enter \" reset \"" << std::endl;
	std::cout << "6. For make alive cell enter \" set <X, Y> \"" << std::endl;
	std::cout << "7. For make death cell enter \" clear<X, Y> \"" << std::endl;
	std::cout << "8. For help enter \"help\"" << std::endl;
	std::cout << "9. For finishing game enter \"exit\"" << std::endl;
}

void View::print_field(Field& f, const unsigned steps)
{
		std::cout << f.get_name() << std::endl;
		std::cout << "step " << steps << std::endl;
		std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << i;
			for (int j = 0; j < 10; j++)
				std::cout << " " << f[i][j].is_alive();
			std::cout << std::endl;
		}
	
}