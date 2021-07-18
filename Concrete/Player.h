#pragma once

class Player
{
private:
	// Int To Store Players Score
	int score = 0;
public:
	Player() {}
	~Player()
	{

	}

	// Return Players Score
	int getScore() { return score; }
	// Increment And Return Players Score
	int incrementScore() { score++; return score; }
	// Reset And Return Players Score
	int reset() { score = 0; return score; }

};