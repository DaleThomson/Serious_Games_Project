#include "QuizInput.h"
#include "Menu.h"
#include "Quiz.h"
void QuizInput::print()
{
	// All Questions and Answers Were Sourced From: https://toptests.co.uk/mock-theory-test/
	std::fstream file("../Resources/Quiz/Questions/Inputs/Question" + std::to_string(Q_num) + ".txt");

	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}

	while (file >> std::noskipws >> check)
	{
		if (check != '*')
		{
			std::cout << check;
		}
	}

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
		if (!questionBackup.is_open())
		{
			std::ofstream backupFix("../Resources/Quiz/QuizBackupPopulator.txt");
			for (int i = 1; i <= 50; i++)
			{
				backupFix << i << std::endl;
				if (i > 49)
					backupFix << i;
			}
			questionBackup.close();
			backupFix.close();
			std::rename("../Resources/Quiz/QuizBackupPopulator.txt", "../Resources/Quiz/QuizPopulate-BACKUP.txt");
			std::fstream questionBackup("../Resources/Quiz/QuizPopulate-BACKUP.txt");
			system("CLS");
			std::cout << "An Error Occured Generating The Question List Please Try Again...\n\n";
			system("PAUSE");
			system("CLS");
			error = true;
			return;
		}
		std::ofstream reloadFile("../Resources/Quiz/QuizBuffer.txt");


		while (getline(questionBackup, line))
		{
			if (std::stoi(line) > 0)
				reloadFile << std::endl << line;
			else
			{
				reloadFile << line << std::endl;
			}
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
	int randomEntry = 0;
	finish = false;

	while (getline(populateFile, line))
	{
		lineNum++;
		inSessionLines.push_back(line);
	}

	if (!removalFile.eof())
	{
		bool populated = true;
		if (inSessionLines.size() == 0)
		{
			finish = true;
			return;
		}
		else
		{
			random = rand() % inSessionLines.size();
		}

		randomEntry = std::stoi(inSessionLines[random]);
		if (populated)
			if (randomEntry == 0)
			{
				random = rand() % inSessionLines.size();
				randomEntry = std::stoi(inSessionLines[random]);
			}
	}
	Q_num = randomEntry;
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
}

void QuizInput::answerHandler(int input)
{
	std::fstream file("../Resources/Quiz/Questions/Inputs/Question" + std::to_string(Q_num) + ".txt");

	char inputChar = '0' + input;
	if (Q_num != 0)
	{
		while (file >> std::noskipws >> check)
		{
			if (check == '*')
			{
				if (file.peek() == inputChar)
				{
					correct = true;
					player->incrementScore();
					system("CLS");
					std::cout << "Correct\n\n";
					system("PAUSE");
					system("CLS");
					break;
				}
			}
		}
		if (!correct)
		{
			system("CLS");
			std::cout << "Incorrect\n\n";
			system("PAUSE");
			system("CLS");
		}
		correct = false;
	}
	questionHandler();
	Q_NumDisplay++;
	if (finish)
	{
		system("CLS");
		std::cout << "You have finished the assessment.\n\n"
			"Your score is: " << player->getScore();
		std::cout << "/50\n\n";
		if (player->getScore() < 43)
		{
			std::cout << "Unfortunately you have failed the assessment. We recommend "
				<< "that you utilize the revision section of the program.\n\n";
		}
		if (player->getScore() >= 43)
		{
			std::cout << "Congratulations you have passed the test!\n\n";
		}
		system("PAUSE");
		player->reset();
		system("CLS");
	}
}

void QuizInput::handleInput(int input, AbstractQuestion** question)
{
	AbstractQuestion* q = *question;
	switch (input)
	{
	case 1:
		system("CLS");
		answerHandler(input);
		if (finish | error)
		{
			*question = new Menu(player);
			delete q;
			break;
		}
		*question = new Quiz(player, Q_num, Q_NumDisplay);
		delete q;
		break;
	case 2:
		system("CLS");
		answerHandler(input);
		if (finish | error)
		{
			*question = new Menu(player);
			delete q;
			break;
		}
		*question = new Quiz(player, Q_num, Q_NumDisplay);
		delete q;
		break;
	case 3:
		system("CLS");
		answerHandler(input);
		if (finish | error)
		{
			*question = new Menu(player);
			delete q;
			break;
		}
		*question = new Quiz(player, Q_num, Q_NumDisplay);
		delete q;
		break;
	case 4:
		system("CLS");
		answerHandler(input);
		if (finish | error)
		{
			*question = new Menu(player);
			delete q;
			break;
		}
		*question = new Quiz(player, Q_num, Q_NumDisplay);
		delete q;
		break;
	case 5:
		system("CLS");
		player->reset();
		*question = new Menu(player);
		delete q;
		break;
	case 9:
		system("CLS");
		std::cout << "Thank you for using our software.\n\n";
		system("PAUSE");
		exit(0);
		break;
	default:
		system("CLS");
		std::cout << "Please Select A Valid Option...\n\n";
		std::cin.clear();
		system("PAUSE");
		system("CLS");
		break;
}
}