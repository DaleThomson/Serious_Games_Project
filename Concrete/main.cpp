#include <iostream>
#include "Menu.h"
#include "Player.h"
int main(int argc, char** argv)
{
	Player* player = new Player();
	AbstractQuestion* question = new Menu(player);
	question->print();
	int input;
	while (true)
	{
		if (std::cin >> input)
		{
			break;
		}
		system("CLS");
		question->print();
		std::cout << "\n\nPlease Enter One Of The Valid Options Listed Above: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (input != 0)
	{
		question->handleInput(input, &question);
		question->print();
		std::cin >> input;
		std::cin.get();
	}
	system("CLS");
	std::cout << "Thank you for using [SOFTWARE PACKAGE]\n\n";
	system("PAUSE");
	return 0;
}