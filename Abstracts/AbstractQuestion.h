#pragma once
#include "AbstractDisplay.h"
#include "AbstractInput.h"
class AbstractQuestion
{
protected:
	AbstractDisplay* display;
	AbstractInput* input;
public:
	virtual ~AbstractQuestion()
	{
		delete display;
		delete input;
	}

	virtual void print() = 0;
	virtual void handleInput(int input, AbstractQuestion** question) = 0;
};