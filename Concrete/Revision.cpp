#include "Revision.h"

void Revision::print()
{
	display->print();
	input->print();
}

void Revision::handleInput(int Input, AbstractQuestion** question)
{
	input->handleInput(Input, question);
}