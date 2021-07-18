#include "RevisionDisplay.h"

void RevisionDisplay::print()
{
	// All Text Relating to the Highway Code is Sourced From: https://www.highwaycodeuk.co.uk/
	std::ifstream file("../Resources/Revision/Revision" + std::to_string(page) + ".txt");

	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}
	
	if (file.is_open())
		std::cout << file.rdbuf();

	file.clear();
	file.seekg(0, file.beg);
}