#pragma once
#include "AbstractInput.h"
#include "Player.h"
class QuizInput : public AbstractInput
{
private:
	int Q_num;
	bool finish;
	char check;
	bool correct;
protected:
	Player* player;
public:
	QuizInput(Player* player, int Q_num) :player(player), Q_num(Q_num) {}
	void print();
	void questionHandler();
	void handleInput(int input, AbstractQuestion** question);
};

