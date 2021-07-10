#pragma once
#include "AbstractInput.h"
#include "Player.h"
class QuizInput : public AbstractInput
{
private:
	int Q_num;
	bool finish;
protected:
	Player* player;
public:
	QuizInput(Player* player, int Q_num) :player(player), Q_num(Q_num) {}
	void print();
	void questionHandler();
	void handleInput(char input, AbstractQuestion** question);
};

