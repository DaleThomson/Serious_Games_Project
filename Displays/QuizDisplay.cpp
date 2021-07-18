#include "QuizDisplay.h"

void QuizDisplay::print()
{
	// All Questions and Answers were sourced from: https://toptests.co.uk/mock-theory-test/
	std::ifstream file("../Resources/Quiz/Questions/Displays/Question" + std::to_string(Q_num) + ".txt");

	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}

	std::cout << "Question Number: " + std::to_string(Q_NumDisplay) << "/50\n\n";
	std::cout << file.rdbuf();
}