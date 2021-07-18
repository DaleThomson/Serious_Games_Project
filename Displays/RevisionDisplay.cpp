#include "RevisionDisplay.h"

void RevisionDisplay::print()
{
	// All Text Relating to the Highway Code is Sourced From: https://www.highwaycodeuk.co.uk/
	// Open File
	std::ifstream file("../Resources/Revision/Revision" + std::to_string(page) + ".txt");

	// If File Does Not Exist Inform The User And Exit The Software
	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}
	
	// If File Exists Print It
	std::cout << file.rdbuf();
}