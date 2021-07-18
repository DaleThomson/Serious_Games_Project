#include "RevisionInput.h"
#include "Revision.h"
#include "Menu.h"
void RevisionInput::print()
{
	// Open File
	std::fstream file("../Resources/Revision/RevisionMenu.txt");

	// If File Does Not Exist Inform The Player And Exit The Software
	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}
	// Print The File
	std::cout << file.rdbuf();
}

void RevisionInput::handleInput(int input, AbstractQuestion** question)
{
	AbstractQuestion* q = *question;
	switch (input)
	{
	case 1:
		system("CLS");
		// Increment Page Num
		page++;
		// Page Num Is Greater Than Page Max Return Player To The Menu
		if (page > pageMax)
		{
			std::cout << "This concludes the revision material. Returning you to the main menu\n\n";
			system("PAUSE");
			system("CLS");
			*question = new Menu(player);
			delete q;
			break;
		}
		// If Page Num Is Less Than Or Equal To Max Page Send The Player To The Next Page
		*question = new Revision(player, page);
		delete q;
		break;
	case 2:
		system("CLS");
		// Reduct The Page Number
		page--;
		// If Page Number Is Less Than 0 Return Player To The Menu
		if (page < 0)
		{
			std::cout << "There is no page before this. Returning you to the main menu\n\n";
			system("PAUSE");
			system("CLS");
			*question = new Menu(player);
			delete q;
			break;
		}
		// If Page Num Is Greater Than 0 Send Player To The Previous Page
		system("CLS");
		*question = new Revision(player, page);
		delete q;
		break;
	case 3:
		// Return Player To Menu
		system("CLS");
		*question = new Menu(player);
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