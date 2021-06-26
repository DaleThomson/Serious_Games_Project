#include "MenuInput.h"
#include "Revision.h"

void MenuInput::print()
{
	std::fstream file("../Resources/Menu/MenuInput.txt");
	while (file >> std::noskipws >> check)
	{
		if (check == '*')
		{

		}
		else
		{
			std::cout << check;
		}
	}
}

void MenuInput::handleInput(char input, AbstractQuestion** question)
{
	std::fstream file("../Resources/Menu/MenuInput.txt");
	AbstractQuestion* q = *question;
	switch (input)
	{
	case ('1'):
		system("CLS");
		delete q;
		break;
	case ('2'):
		system("CLS");
		while (file >> std::noskipws >> check)
		{
			if (check == '*')
			{
				if (file.peek() == '1')
				{
					player->incrementScore();
					std::cout << "Congratulations\n\n";
					std::cout << player->getScore();
					system("PAUSE");
					system("CLS");
				}
			}
		}
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