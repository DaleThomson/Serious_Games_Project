#pragma once
#include "AbstractInput.h"
#include "Player.h"
class QuizInput : public AbstractInput
{
private:
	int Q_num;
	int Q_NumDisplay;
	bool finish;
	char check;
	char i;
	bool correct;
	bool error;
protected:
	Player* player;
public:
	QuizInput(Player* player, int Q_num, int Q_NumDisplay) :player(player), Q_num(Q_num), Q_NumDisplay(Q_NumDisplay) {}
	void print();
	void questionHandler();
	void answerHandler(int input);
	void handleInput(int input, AbstractQuestion** question);
};

