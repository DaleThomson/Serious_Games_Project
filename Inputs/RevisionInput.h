#pragma once
#include "AbstractInput.h"
#include "Player.h"
class RevisionInput : public AbstractInput
{
private:
	int page;
protected:
	Player* player;
public:
	RevisionInput(Player* player, int page) :player(player), page(page) {}
	void print();
	void handleInput(char input, AbstractQuestion** question);
};

