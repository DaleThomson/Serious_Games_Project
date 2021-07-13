#pragma once
#include "AbstractQuestion.h"
#include "Player.h"
#include "QuizDisplay.h"
#include "QuizInput.h"

class Quiz : public AbstractQuestion
{
private:
	int Q_numPass;
public:
	Quiz(Player* player, int Q_num)
	{
		Q_numPass = Q_num;
		display = new QuizDisplay(Q_numPass);
		input = new QuizInput(player, Q_numPass);
	}

	virtual ~Quiz() {
	}

	void print();
	void handleInput(int input, AbstractQuestion** question);
};