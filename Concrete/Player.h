#pragma once

class Player
{
private:
	int score = 0;

public:
	Player() {}
	~Player()
	{

	}

	int getScore() { return score; }
	int incrementScore() { score++; return score; }
	int reset() { score = 0; }

};