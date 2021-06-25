#include "MenuInput.h"
#include "Revision.h"

void MenuInput::print()
{
	std::fstream file("../Resources/Menu/MenuInput1.txt");

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
		exit(0);
	default:
		system("CLS");
		std::cout << "Please Select A Valid Option...\n\n";
		system("PAUSE");
		system("CLS");
		break;
	}
}