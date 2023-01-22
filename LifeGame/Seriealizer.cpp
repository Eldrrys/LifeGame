#include "Serealizer.h"

Serealizer::Serealizer(Field& f) : field(f)
{
}

Serealizer::~Serealizer()
{
}

void Serealizer::store_field(std::string& filename)
{
	std::ofstream file(filename);
	file << "#N " << field.get_name() << std::endl;
	file << "#R " << rules.rules_to_string() << std::endl;
	for (unsigned i = 0; i < FIELD_SIZE; i++)
	{
		for (unsigned j = 0; j < FIELD_SIZE; j++)
			if (field[i][j].alive()) file << i << " " << j << std::endl;
	}
	file.close();
}
