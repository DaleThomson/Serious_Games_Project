#include "QuizDisplay.h"

void QuizDisplay::print()
{
	std::ifstream file("../Resources/Menu/Menu.txt");

	std::cout << file.rdbuf();
}