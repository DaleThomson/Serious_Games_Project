#include "MenuInput.h"
#include "Revision.h"
#include "Quiz.h"


void MenuInput::print()
{
	std::fstream file("../Resources/Menu/MenuInput.txt");
	
	std::cout << file.rdbuf();
}
void MenuInput::handleInput(int input, AbstractQuestion** question)
{
	//while (!(std::cin >> input))
	//{
	//	std::cout << "\n\nPlease Enter One Of The Valid Options Listed Above: ";
	//	std::cin.clear();
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//}
	AbstractQuestion* q = *question;
	switch (input)
	{
	case 1:
		system("CLS");
		*question = new Quiz(player, 0);
		delete q;
		break;
	case 2:
		system("CLS");
		*question = new Revision(player, 1);
		delete q;
		break;
	case 0:
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