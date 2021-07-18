#pragma once
#include "AbstractInput.h"
#include "Player.h"
class RevisionInput : public AbstractInput
{
private:
	// Int To Store Page Number
	int page;
	// Int To Store Max Page Number
	int pageMax = 135;
protected:
	// Protected Pointer To Player To Allow Pass Into Constructor
	Player* player;
public:
	// Constructor
	RevisionInput(Player* player, int page) :player(player), page(page) {}
	// Print Function
	void print();
	// Handle Input Function
	void handleInput(int input, AbstractQuestion** question);
};

