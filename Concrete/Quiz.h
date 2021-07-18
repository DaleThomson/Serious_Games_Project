#pragma once
#include "AbstractQuestion.h"
#include "Player.h"
#include "QuizDisplay.h"
#include "QuizInput.h"

class Quiz : public AbstractQuestion
{
private:
	// Int To Store Random Number To Be Passed Into Constructor
	int Q_numPass;
	// Int To Store Incremental Question Number To Be Passed Into Constructor
	int Q_numDisplay;
public:
	// Constructor
	Quiz(Player* player, int Q_num, int Q_num_display)
	{
		Q_numPass = Q_num;
		Q_numDisplay = Q_num_display;
		display = new QuizDisplay(Q_numPass, Q_numDisplay);
		input = new QuizInput(player, Q_numPass, Q_numDisplay);
	}

	virtual ~Quiz() {
	}
	// Print Method
	void print();
	// Input Handling Method
	void handleInput(int input, AbstractQuestion** question);
};