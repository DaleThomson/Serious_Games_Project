#pragma once
#include "AbstractDisplay.h"
#include "AbstractInput.h"
class AbstractQuestion
{
// Abstract Class To Create Instances
protected:
	// Protected Pointers To Be Assigned To Concrete Classes
	AbstractDisplay* display;
	AbstractInput* input;
public:
	virtual ~AbstractQuestion()
	{
		delete display; // Delete Contents Of Display Pointer
		delete input; // Delete Contents Of Input Pointer
	}
	// Virtual Print Method To Be Assigned
	virtual void print() = 0;
	// Virtual Input Handler To Be Assigned
	virtual void handleInput(int input, AbstractQuestion** question) = 0;
};