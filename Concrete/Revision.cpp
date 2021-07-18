#include "Revision.h"

void Revision::print()
{
	// Print This Instances Display
	display->print();
	// Print This Instances Input Menu
	input->print();
}

void Revision::handleInput(int Input, AbstractQuestion** question)
{
	// Handle The Players Input In This Instance
	input->handleInput(Input, question);
}