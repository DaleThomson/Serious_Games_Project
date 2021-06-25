#pragma once
#include "AbstractDisplay.h"
class RevisionDisplay : public AbstractDisplay
{
private:
	int page;
public:
	RevisionDisplay(int page) :page(page) {}
	void print();
};

