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
	void handleInput(char input, AbstractQuestion** question);
};

