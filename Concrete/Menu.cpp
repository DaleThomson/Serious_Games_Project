#include "Menu.h"

void Menu::print()
{
	display->print();
	input->print();
}

void Menu::handleInput(int Input, AbstractQuestion** question)
{
	input->handleInput(Input, question);
}