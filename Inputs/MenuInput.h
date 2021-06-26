#pragma once
#include "AbstractInput.h"
#include "Player.h"
#include <iostream>
class MenuInput : public AbstractInput 
{
private:
	char check;
protected:
	Player* player;
public:
	MenuInput(Player* player) :player(player) {}
	void print();
	void handleInput(char input, AbstractQuestion** question);
};

