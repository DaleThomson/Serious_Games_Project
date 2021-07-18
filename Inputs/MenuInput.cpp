#include "MenuInput.h"
#include "Revision.h"
#include "Quiz.h"


void MenuInput::print()
{
	// Open File
	std::fstream file("../Resources/Menu/MenuInput.txt");

	// If File Does Not Exist Inform The User And Exit Software
	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}
	
	// If File Does Exist Print It
	std::cout << file.rdbuf();
}
void MenuInput::handleInput(int input, AbstractQuestion** question)
{
	// Set A Pointer To Equal The Passed In Instance.
	AbstractQuestion* q = *question;
	// Handle User Input
	switch (input)
	{
	case 1:
		system("CLS");
		// Create Quiz Instance and Pass Player In
		// Set Quiz Number to 0
		// Set Quiz Number Display to 0
		*question = new Quiz(player, 0, 0);
		// Delete The Pointer
		delete q;
		break;
	case 2:
		system("CLS");
		// Create Revision Instance and Pass Player In
		// Set Page Number to 0
		*question = new Revision(player, 0);
		// Delete Pointer
		delete q;
		break;
	}
}