#pragma once
#include "AbstractInput.h"
#include "Player.h"
class MenuInput : public AbstractInput 
{
protected:
	Player* player;
public:
	MenuInput(Player* player) :player(player) {}
	void print();
	void handleInput(int input, AbstractQuestion** question);
};

