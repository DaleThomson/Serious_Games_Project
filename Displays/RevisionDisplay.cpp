#include "RevisionDisplay.h"

void RevisionDisplay::print()
{
	std::ifstream file("../Resources/Revision/Revision" + std::to_string(page) + ".txt");
	
	if (file.is_open())
		std::cout << file.rdbuf();

	file.clear();
	file.seekg(0, file.beg);
}