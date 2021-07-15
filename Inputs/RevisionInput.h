#pragma once
#include "AbstractInput.h"
#include "Player.h"
class RevisionInput : public AbstractInput
{
private:
	int page;
	int pageMax = 135;
protected:
	Player* player;
public:
	RevisionInput(Player* player, int page) :player(player), page(page) {}
	void print();
	void handleInput(int input, AbstractQuestion** question);
};

