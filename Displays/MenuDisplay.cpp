#include "MenuDisplay.h"

void MenuDisplay::print()
{
	std::ifstream file("../Resources/Menu/Menu.txt");

	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}

	std::cout << file.rdbuf();
}