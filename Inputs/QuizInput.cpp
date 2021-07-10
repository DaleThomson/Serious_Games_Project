#include "QuizInput.h"
#include "Menu.h"
#include "Quiz.h"
void QuizInput::print()
{
	std::fstream file("../Resources/Quiz/Questions/Inputs/Question" + std::to_string(Q_num) + ".txt");

	std::cout << file.rdbuf();

	file.close();
}


void QuizInput::questionHandler()
{
	std::string line;
	std::fstream populateFile("../Resources/Quiz/QuizPopulate.txt");
	std::ofstream removalFile("../Resources/Quiz/QuizPopulateInSession.txt");

	if (Q_num == 0)
	{
		std::fstream questionBackup("../Resources/Quiz/QuizPopulate-BACKUP.txt");
		std::ofstream reloadFile("../Resources/Quiz/QuizBuffer.txt");
		while (getline(questionBackup, line))
		{
			reloadFile << line << std::endl;
		}
		questionBackup.close();
		reloadFile.close();
		populateFile.close();
		std::remove("../Resources/Quiz/QuizPopulate.txt");
		std::rename("../Resources/Quiz/QuizBuffer.txt", "../Resources/Quiz/QuizPopulate.txt");
		populateFile.clear();
		populateFile.seekg(0);
	}
	if (populateFile.is_open() == 0)
	{
		populateFile.open("../Resources/Quiz/QuizPopulate.txt");
	}
	srand((time(0)));
	int lineNum = 0;
	std::string deleteLine;
	std::vector<std::string> inSessionLines;
	int random = 0;
	finish = false;

	while (getline(populateFile, line))
	{
		lineNum++;
		inSessionLines.push_back(line);
	}

	if (removalFile.eof())
	{
		finish = true;
		return;
	}

	if (!removalFile.eof())
	{
		bool populated = true;
		random = rand() % lineNum;
		if (populated)
			if (random == 0)
				random = rand() % lineNum;
	}
	Q_num = random;
	populateFile.clear();
	populateFile.seekg(0);
	lineNum = 0;

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
	if (random == 0)
	{
		finish = true;
		return;
	}
}

void QuizInput::handleInput(char input, AbstractQuestion** question)
{
	questionHandler();
	if (finish)
	{
		system("CLS");
		std::cout << "You have finished the assessment.\n\n"
			"Your score is: " << player->getScore(); 
		std::cout << std::endl << std::endl;
		system("PAUSE");
		player->reset();
		*question = new Menu(player);
	}
	AbstractQuestion* q = *question;
	switch (input)
	{
	case ('1'):
		system("CLS");
		*question = new Quiz(player, Q_num);
		delete q;
		break;
	case ('2'):
		system("CLS");
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