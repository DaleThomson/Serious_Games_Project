#include <iostream>
#include "Menu.h"
#include "Player.h"
int main(int argc, char** argv)
{
	Player* player = new Player();
	AbstractQuestion* question = new Menu(player);
	question->print();
	char input;
	std::cin >> input;
	std::cin.get();
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