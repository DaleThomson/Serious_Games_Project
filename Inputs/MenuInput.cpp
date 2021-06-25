#include "MenuInput.h"
#include "Revision.h"

void MenuInput::print()
{
	std::fstream file("../Resources/Menu/MenuInput.txt");

	std::cout << file.rdbuf();
}

void MenuInput::handleInput(char input, AbstractQuestion** question)
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
		*question = new Revision(player, 1);
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