#include "MenuDisplay.h"

void MenuDisplay::print()
{
	std::ifstream file("../Resources/Menu/Menu.txt");

	std::cout << file.rdbuf();
}