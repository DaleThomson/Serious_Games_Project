#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <vector>
class AbstractQuestion;

class AbstractInput {
public:
	virtual void print() = 0;
	virtual void handleInput(char input, AbstractQuestion** question) = 0;
};