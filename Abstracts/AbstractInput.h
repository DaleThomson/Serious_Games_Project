#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <vector>
// Allows For Abstract Question Pointer In Input Handler
class AbstractQuestion;

class AbstractInput {
public:
	// Virtual Print Method To Be Assigned
	virtual void print() = 0;
	// Virtual Input Handler To Be Assigned
	virtual void handleInput(int input, AbstractQuestion** question) = 0;
};