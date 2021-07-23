#include "QuizDisplay.h"

void QuizDisplay::print()
{
	// All Questions and Answers were sourced from: https://toptests.co.uk/mock-theory-test/
	// Open File
	std::ifstream file("../Resources/Quiz/Questions/Displays/Question" + std::to_string(Q_num) + ".txt");

	// If File Does Not Exist Inform The User And Exit The Software
	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}
	//If File Does Exist Print The Question Number and Print The File.
	if (Q_num != 0)
	{
		std::cout << "Question Number: " + std::to_string(Q_NumDisplay) << "/50\n\n";
	}
	std::cout << file.rdbuf();
}