#pragma once
#include "AbstractDisplay.h"
class QuizDisplay : public AbstractDisplay
{
private:
	// Int To Store Random Question Number
	int Q_num;
	// Int To Store Incremental Question Number
	int Q_NumDisplay;
public:
	// Constructor
	QuizDisplay(int Q_num, int Q_NumDisplay) :Q_num(Q_num), Q_NumDisplay(Q_NumDisplay) {}
	// Print Method
	void print();
};

