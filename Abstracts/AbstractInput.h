#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
class AbstractQuestion;

class AbstractInput {
public:
	virtual void print() = 0;
	virtual void handleInput(char input, AbstractQuestion** question) = 0;
};