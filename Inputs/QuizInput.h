#pragma once
#include "AbstractInput.h"
#include "Player.h"
class QuizInput : public AbstractInput
{
private:
	// Int To Store Random Question Number
	int Q_num;
	// Int To Display Incremental Question Numbers
	int Q_NumDisplay;
	// Bool To Check If Quiz Is Finished
	bool finish;
	// Char To Check For Asterisks
	char check;
	// Bool To Check If Answer Is Correct
	bool correct;
	// Bool To Check For Errors
	bool error;
protected:
	// Protected Pointer To Player To Allow Pass Through Into Constructor
	Player* player;
public:
	// Constructor
	QuizInput(Player* player, int Q_num, int Q_NumDisplay) :player(player), Q_num(Q_num), Q_NumDisplay(Q_NumDisplay) {}
	// Print Method
	void print();
	// Question Handler Method
	void questionHandler();
	// Answer Handler Method
	void answerHandler(int input);
	// Input Handler Method
	void handleInput(int input, AbstractQuestion** question);
	// Input Checker
	void inputChecker(int input);
};

