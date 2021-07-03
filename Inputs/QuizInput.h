#pragma once
#include "AbstractInput.h"
#include "Player.h"
class QuizInput : public AbstractInput
{
private:
	int Q_num;
protected:
	Player* player;
public:
	QuizInput(Player* player, int Q_num) :player(player), Q_num(Q_num) {}
	void print();
	void populate();
	void handleInput(char input, AbstractQuestion** question);
};

