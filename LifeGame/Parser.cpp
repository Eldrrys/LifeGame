#include "Parser.h"

Parser::Parser() 
{
}


Parser::~Parser()
{
}

std::string Parser::parser_command()
{
	std::string buf;
	std::cin >> buf;
	std::string COMMAND = "0" , HELP = "1" , SAVE = "2", LOAD = "3", EXIT = "4", EXCEPTION = "5";
	system("CLS");

	if (buf == "set" || buf == "back" || buf == "reset" || buf == "clear" || buf == "step" || !wrong_value(buf))
	{
		try
		{
			COMMAND += parser_strategy_arguments( buf);
		}
		catch (std::invalid_argument) {
			std::cout << "The coordinates of the cell for commands\
										 set and reset must be in the format XY , X=0-9, Y=0-9\n";
		}
		catch (char*)
		{
			std::cout << "The number before which was no step or back\n";
		}
		return COMMAND;
	}
	else if (buf == "save")
	{
		try { SAVE = SAVE + write_file(); }
		catch (std::invalid_argument) { std::cout << "Could not open file for saving\n"; }
		return SAVE;
	}
	else if (buf == "load")
	{
		try { LOAD = LOAD + read_file(); }
		catch (std::invalid_argument) { std::cout << "Could not open file for download\n"; }
		return LOAD;
	}
	else if (buf == "help")
		return HELP;

	else if (buf == "exit")
		return EXIT;

	else
		return EXCEPTION;
}

std::string& Parser::parser_strategy_arguments(std::string& buf)
{
	static std::string com;
	static int st_or_bc = false;
	          if (buf == "reset") com = "0";
	     else if (buf == "set") com = "1"; else if (buf == "clear") com = "2";
		 else if (buf == "step") com = "3"; else if (buf == "back") com = "4";
	if (buf == "set" || buf == "clear")
	{
		std::cin >> buf; 
		if (wrong_arguments(buf))
			throw std::invalid_argument("WRONG COORDINATES");
		buf = com + buf;
	}
	else if (buf == "step" || buf == "back")
	{
		buf = com + "1"; 
		st_or_bc = true;
	}
	else if (!wrong_value(buf) && st_or_bc)
	{
		if (buf == "1") buf = com + "0";
		else buf = com + buf;
		st_or_bc = false;
	}

	else if (buf == "reset") buf = com;
	else if (!st_or_bc) throw "WRONG COMMAND";
	return buf;
}

bool Parser::wrong_arguments(std::string name) 
{
	return !(name[0] >= '0' && name[0] <= '9' && name[1] >= '0' && name[1] <= '9');
}

bool Parser::wrong_value(std::string name)
{
	for (unsigned i = 0; i < name.size(); i++)
		if (!isdigit(name[i]))
			return true;
	return false;
}

std::string& Parser::write_file()
{
	static std::string filename;
	std::cin >> filename;
	std::ofstream file;
	file.open(filename);
	if (!file.is_open())
		throw std::invalid_argument("Output file is not opened");
	file.close();
	return filename;
}

std::string& Parser::read_file()
{

	static std::string filename;
	std::cin >> filename;
	std::ifstream file;
	file.open(filename);
	if (!file.is_open())
		throw std::invalid_argument("Input file is not opened");
	file.close();
	return filename;
}