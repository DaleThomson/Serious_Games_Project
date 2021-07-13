#include "Quiz.h"

void Quiz::print()
{
	display->print();
	input->print();
}

void Quiz::handleInput(int Input, AbstractQuestion** question)
{
	input->handleInput(Input, question);
}