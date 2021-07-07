#include "QuizInput.h"
#include <errno.h>

void QuizInput::print()
{
	std::fstream file("../Resources/Quiz/QuizInput.txt");

	std::cout << file.rdbuf();

	file.close();
}


void QuizInput::questionHandler()
{
	std::fstream populateFile("../Resources/Quiz/QuizPopulate.txt");
	std::ofstream removalFile("../Resources/Quiz/QuizPopulateInSession.txt");

	srand((time(0)));
	int lineNum = 0;
	std::string line;
	std::string deleteLine;
	std::vector<std::string> inSessionLines;

	int keepLine = 0;
	

	while (getline(populateFile, line))
	{
		lineNum++;
		inSessionLines.push_back(line);
	}
	int random = rand() % lineNum;
	std::cout << inSessionLines[random];
	lineNum = 0;
	//populateFile.clear();
	//populateFile.seekg(0);
	while (getline(populateFile, line))
	{
		++lineNum;
		if (lineNum == random + 1)
		{
			deleteLine = line;
		}
		if (line != deleteLine)
		{
			removalFile << line << std::endl;
		}
	}
	populateFile.close();
	removalFile.close();
	std::remove("../Resources/Quiz/QuizPopulate.txt");
	std::rename("../Resources/Quiz/QuizPopulateInSession.txt", "../Resources/Quiz/QuizPopulate.txt");
}

void QuizInput::handleInput(char input, AbstractQuestion** question)
{
	//std::string line;
	//srand((time(0)));
	//int random = rand() % 50;
	//int lineNum = 0;
	AbstractQuestion* q = *question;
	switch (input)
	{
	case ('1'):
		system("CLS");
		delete q;
		break;
	case ('2'):
		system("CLS");
		questionHandler();
		//delete q;
		break;
	case ('0'):
		system("CLS");
		std::cout << "Thank you for using our software.\n\n";
		system("PAUSE");
		exit(0);
	default:
		system("CLS");
		std::cout << "Please Select A Valid Option...\n\n";
		system("PAUSE");
		system("CLS");
		break;
	}
}