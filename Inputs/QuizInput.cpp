#include "QuizInput.h"

void QuizInput::print()
{
	std::fstream file("../Resources/Quiz/Question" + std::to_string(Q_num) + ".txt");

	std::cout << file.rdbuf();
}
void QuizInput::handleInput(char input, AbstractQuestion** question)
{
	AbstractQuestion* q = *question;
	switch (input)
	{
	case ('1'):
		system("CLS");
		delete q;
		break;
	case ('2'):
		system("CLS");
		delete q;
		break;
	case ('0'):
		system("CLS");
		std::cout << "Thank you for using our software.\n\n";
		system("PAUSE");
		exit(0);
	default:
		system("CLS");
		std::cout << "Please Select A Valid Option...\n\n";
		system("PAUSE");
		system("CLS");
		break;
	}
}