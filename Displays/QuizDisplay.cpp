#include "QuizDisplay.h"

void QuizDisplay::print()
{
	std::ifstream file("../Resources/Quiz/Questions/Displays/Question" + std::to_string(Q_num) + ".txt");
	std::cout << "Question Number: " + std::to_string(Q_NumDisplay) << "/50\n\n";
	std::cout << file.rdbuf();
}