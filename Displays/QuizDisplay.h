#pragma once
#include "AbstractDisplay.h"
class QuizDisplay : public AbstractDisplay
{
private:
	int Q_num;
	int Q_NumDisplay;
public:
	QuizDisplay(int Q_num, int Q_NumDisplay) :Q_num(Q_num), Q_NumDisplay(Q_NumDisplay) {}
	void print();
};

