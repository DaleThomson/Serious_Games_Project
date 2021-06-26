#pragma once
#include "AbstractDisplay.h"
class QuizDisplay : public AbstractDisplay
{
private:
	int Q_num;
public:
	QuizDisplay(int Q_num) :Q_num(Q_num) {}
	void print();
};

