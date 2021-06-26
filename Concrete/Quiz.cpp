#include "Quiz.h"

void Quiz::print()
{
	display->print();
	input->print();
}

void Quiz::handleInput(char Input, AbstractQuestion** question)
{
	input->handleInput(Input, question);
}