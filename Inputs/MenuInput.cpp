#include "MenuInput.h"
#include "Revision.h"
#include "Quiz.h"


void MenuInput::print()
{
	std::fstream file("../Resources/Menu/MenuInput.txt");

	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}
	
	std::cout << file.rdbuf();
}
void MenuInput::handleInput(int input, AbstractQuestion** question)
{
	AbstractQuestion* q = *question;
	switch (input)
	{
	case 1:
		system("CLS");
		*question = new Quiz(player, 0, 0);
		delete q;
		break;
	case 2:
		system("CLS");
		*question = new Revision(player, 0);
		delete q;
		break;
	case 9:
		system("CLS");
		std::cout << "Thank you for using our software.\n\n";
		system("PAUSE");
		exit(0);
		break;
	default:
		system("CLS");
		std::cout << "Please Select A Valid Option...\n\n";
		std::cin.clear();
		system("PAUSE");
		system("CLS");
		break;
	}
}