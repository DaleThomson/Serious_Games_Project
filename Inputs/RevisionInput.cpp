#include "RevisionInput.h"
#include "Revision.h"
#include "Menu.h"
void RevisionInput::print()
{
	std::fstream file("../Resources/Revision/RevisionMenu.txt");

	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}

	std::cout << file.rdbuf();

	file.close();
}

void RevisionInput::handleInput(int input, AbstractQuestion** question)
{
	AbstractQuestion* q = *question;
	switch (input)
	{
	case 1:
		system("CLS");
		page++;
		if (page > pageMax)
		{
			std::cout << "This concludes the revision material. Returning you to the main menu\n\n";
			system("PAUSE");
			system("CLS");
			*question = new Menu(player);
			delete q;
			break;
		}
		*question = new Revision(player, page);
		delete q;
		break;
	case 2:
		system("CLS");
		page--;
		if (page < 0)
		{
			std::cout << "There is no page before this. Returning you to the main menu\n\n";
			system("PAUSE");
			system("CLS");
			*question = new Menu(player);
			delete q;
			break;
		}
		system("CLS");
		*question = new Revision(player, page);
		delete q;
		break;
	case 3:
		system("CLS");
		*question = new Menu(player);
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