#include "MenuInput.h"

void MenuInput::print()
{
	std::cout << "1. Access the mock assessment.\n"
		"2: Access revision materials.\n"
		"0: Exit software\n\n"

	"Please Enter Your Selection: ";
}

void MenuInput::handleInput(int input, AbstractQuestion** question)
{
	AbstractQuestion* q = *question;
	switch (input)
	{
	case 1:
		system("CLS");
		*question = 0;
		delete q;
		break;
	case 2:
		system("CLS");
		*question = 0;
		delete q;
		break;
	default:
		system("CLS");
		std::cout << "Please Select A Valid Option...\n\n";
		system("PAUSE");
		system("CLS");
		print();
		break;
	}
}