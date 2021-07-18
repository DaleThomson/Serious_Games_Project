#pragma once
#include "AbstractDisplay.h"
class RevisionDisplay : public AbstractDisplay
{
private:
	// Int To Store Page
	int page;
public:
	// Constructor
	RevisionDisplay(int page) :page(page) {}
	// Print Method
	void print();
};