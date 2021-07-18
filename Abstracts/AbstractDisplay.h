#pragma once
#include <string>
#include <iostream>
#include <fstream>
class AbstractDisplay {
public:
	// Virtual Print Method To Be Assigned
	virtual void print() = 0;
};