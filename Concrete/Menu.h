#pragma once
#include "AbstractQuestion.h"
#include "Player.h"
#include "MenuDisplay.h"
#include "MenuInput.h"

class Menu : public AbstractQuestion
{
public:
	// Constructor
	Menu(Player* player)
	{
		// Create Display And Input, Pass Player To Input
		display = new MenuDisplay();
		input = new MenuInput(player);
	}

	virtual ~Menu() {}

	void print();
	void handleInput(int input, AbstractQuestion** question);
};