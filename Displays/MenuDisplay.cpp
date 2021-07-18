#include "MenuDisplay.h"

void MenuDisplay::print()
{
	//Open File
	std::ifstream file("../Resources/Menu/Menu.txt");

	// If File Does Not Exist Then Inform The User and Exit The Software
	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}

	// If File Exists Then Print It
	std::cout << file.rdbuf();
}