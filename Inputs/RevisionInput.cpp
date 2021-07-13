#include "RevisionInput.h"
#include "Revision.h"
#include "Menu.h"
void RevisionInput::print()
{
	std::fstream file("../Resources/Revision/RevisionMenu.txt");

	std::cout << file.rdbuf();

	file.close();
}

void RevisionInput::handleInput(int input, AbstractQuestion** question)
{
	AbstractQuestion* q = *question;
	switch (input)
	{
	case ('1'):
		system("CLS");
		page++;
		if (page > pageMax)
		{
			system("CLS");
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
	case ('2'):
		system("CLS");
		*question = 0;
		delete q;
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