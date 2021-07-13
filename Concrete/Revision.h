#pragma once
#include "AbstractQuestion.h"
#include "Player.h"
#include "RevisionDisplay.h"
#include "RevisionInput.h"

class Revision : public AbstractQuestion
{
private:
	int pagePass;
public:
	Revision(Player* player, int page)
	{
		pagePass = page;
		display = new RevisionDisplay(pagePass);
		input = new RevisionInput(player, pagePass);
	}

	virtual ~Revision() {
	}

	void print();
	void handleInput(int input, AbstractQuestion** question);
};