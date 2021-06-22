#pragma once
#include <string>
#include <iostream>
#include <fstream>
class AbstractQuestion;

class AbstractInput {
public:
	virtual void print() = 0;
	virtual void handleInput(int input, AbstractQuestion** question) = 0;
};