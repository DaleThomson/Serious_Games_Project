#pragma once
#include "AbstractInput.h"
#include "Player.h"
class MenuInput : public AbstractInput 
{
protected:
	// Protected Pointer To Player To Allow Pass Through Into Constructor
	Player* player;
public:
	// Constructor
	MenuInput(Player* player) :player(player) {}
	// Print Method
	void print();
	// Input Handler Method
	void handleInput(int input, AbstractQuestion** question);
};

