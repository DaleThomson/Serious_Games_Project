#pragma once
#include "AbstractQuestion.h"
#include "Player.h"
#include "QuizDisplay.h"
#include "QuizInput.h"

class Quiz : public AbstractQuestion
{
private:
	int Q_numPass;
	int Q_numDisplay;
public:
	Quiz(Player* player, int Q_num, int Q_num_display)
	{
		Q_numPass = Q_num;
		Q_numDisplay = Q_num_display;
		display = new QuizDisplay(Q_numPass, Q_numDisplay);
		input = new QuizInput(player, Q_numPass, Q_numDisplay);
	}

	virtual ~Quiz() {
	}

	void print();
	void handleInput(int input, AbstractQuestion** question);
};