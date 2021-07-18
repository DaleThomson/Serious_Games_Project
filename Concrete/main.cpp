#include <iostream>
#include "Menu.h"
#include "Player.h"
int main(int argc, char** argv)
{
	//Creates Player
	Player* player = new Player();
	// Assigns A Instance For The User To Control In This Case The Menu
	AbstractQuestion* question = new Menu(player);
	// Prints Instances Display
	question->print();
	// Int To Store Players Input
	int input;
	// Creates An Endless Loop
	while (true)
	{
		// Asks For The Players Input
		if (std::cin >> input)
		{
			// While Input Does Not Equal Zero Process the Code
			while (input != 0)
			{
				// Checks The Players Input Against The Instances Cases And Reacts Accordingly
				question->handleInput(input, &question);
				// Prints The New Instances Display
				question->print();
				// Ask Again For The Players Input
				std::cin >> input;
				// Get Input
				std::cin.get();
			}
			// If The 0 Is Entered The Code Jumps Out The Loop and Exits
			if (input == 0)
			{
				exit(0);
			}
		}
		// Clear Screen
		system("CLS");
		// Reprint Instance Display
		question->print();
		// A Message Prompting The User To Re-Enter Their Selection
		std::cout << "\n\nPlease Enter One Of The Valid Options Listed Above: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return 0;
}