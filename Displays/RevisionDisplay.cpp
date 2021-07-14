#include "RevisionDisplay.h"

void RevisionDisplay::print()
{
	// All Text Relating to the Highway Code is Sourced From: https://www.highwaycodeuk.co.uk/
	std::ifstream file("../Resources/Revision/Revision" + std::to_string(page) + ".txt");
	
	if (file.is_open())
		std::cout << file.rdbuf();

	file.clear();
	file.seekg(0, file.beg);
}