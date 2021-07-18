#include "Quiz.h"

void Quiz::print()
{
	// Print This Instances Display
	display->print();
	// Print This Instances Input Menu
	input->print();
}

void Quiz::handleInput(int Input, AbstractQuestion** question)
{
	// Handle The Players Input In This Instance
	input->handleInput(Input, question);
}