#include "QuizInput.h"
#include "Menu.h"
#include "Quiz.h"
void QuizInput::print()
{
	std::fstream file("../Resources/Quiz/Questions/Inputs/Question" + std::to_string(Q_num) + ".txt");
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

void QuizInput::handleInput(int input, AbstractQuestion** question)
{
	std::fstream file("../Resources/Quiz/Questions/Inputs/Question" + std::to_string(Q_num) + ".txt");
	AbstractQuestion* q = *question;
	switch (input)
	{
	case 1:
		system("CLS");
		if (Q_num != 0)
		{
			while (file >> std::noskipws >> check)
			{
				if (check == '*')
				{
					if (file.peek() == '1')
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
		if (finish)
		{
			system("CLS");
			std::cout << "You have finished the assessment.\n\n"
				"Your score is: " << player->getScore();
			std::cout << std::endl << std::endl;
			system("PAUSE");
			player->reset();
			system("CLS");
			*question = new Menu(player);
			delete q;
			break;
		}
		Q_NumDisplay++;
		*question = new Quiz(player, Q_num, Q_NumDisplay);
		delete q;
		break;
	case 2:
		system("CLS");
		if (Q_num != 0)
		{
			while (file >> std::noskipws >> check)
			{
				if (check == '*')
				{
					if (file.peek() == '2')
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
		if (finish)
		{
			system("CLS");
			std::cout << "You have finished the assessment.\n\n"
				"Your score is: " << player->getScore();
			std::cout << std::endl << std::endl;
			system("PAUSE");
			player->reset();
			system("CLS");
			*question = new Menu(player);
			delete q;
			break;
		}
		Q_NumDisplay++;
		*question = new Quiz(player, Q_num, Q_NumDisplay);
		delete q;
		break;
	case 3:
		system("CLS");
		if (Q_num != 0)
		{
			while (file >> std::noskipws >> check)
			{
				if (check == '*')
				{
					if (file.peek() == '3')
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
		if (finish)
		{
			system("CLS");
			std::cout << "You have finished the assessment.\n\n"
				"Your score is: " << player->getScore();
			std::cout << std::endl << std::endl;
			system("PAUSE");
			player->reset();
			system("CLS");
			*question = new Menu(player);
			delete q;
			break;
		}
		Q_NumDisplay++;
		*question = new Quiz(player, Q_num, Q_NumDisplay);
		delete q;
		break;
	case 4:
		system("CLS");
		if (Q_num != 0)
		{
			while (file >> std::noskipws >> check)
			{
				if (check == '*')
				{
					if (file.peek() == '4')
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
		if (finish)
		{
			system("CLS");
			std::cout << "You have finished the assessment.\n\n"
				"Your score is: " << player->getScore();
			std::cout << std::endl << std::endl;
			system("PAUSE");
			player->reset();
			system("CLS");
			*question = new Menu(player);
			delete q;
			break;
		}
		Q_NumDisplay++;
		*question = new Quiz(player, Q_num, Q_NumDisplay);
		delete q;
		break;
	case ('0'):
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