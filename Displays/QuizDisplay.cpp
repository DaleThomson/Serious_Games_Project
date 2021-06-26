#include "QuizDisplay.h"

void QuizDisplay::print()
{
	std::ifstream file("../Resources/Menu/Menu" + std::to_string(Q_num) + ".txt");

	std::cout << file.rdbuf();
}