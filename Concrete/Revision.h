#pragma once
#include "AbstractQuestion.h"
#include "Player.h"
#include "RevisionDisplay.h"
#include "RevisionInput.h"

class Revision : public AbstractQuestion
{
private:
	// Int To Pass Page Num Into Constructor
	int pagePass;
public:
	// Constructor
	Revision(Player* player, int page)
	{
		pagePass = page;
		display = new RevisionDisplay(pagePass);
		input = new RevisionInput(player, pagePass);
	}

	virtual ~Revision() {
	}
	// Print Method
	void print();
	// Input Handler Method
	void handleInput(int input, AbstractQuestion** question);
};