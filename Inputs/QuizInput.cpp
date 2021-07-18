#include "QuizInput.h"
#include "Menu.h"
#include "Quiz.h"
void QuizInput::print()
{
	// All Questions and Answers Were Sourced From: https://toptests.co.uk/mock-theory-test/
	// Open File
	std::fstream file("../Resources/Quiz/Questions/Inputs/Question" + std::to_string(Q_num) + ".txt");

	// If File Does Not Exist Then Inform The User and Exit The Software
	if (!file.is_open())
	{
		system("CLS");
		std::cout << "You Are Missing A Display File Please Re-Download The Software\n\n";
		std::cout << "The Software Will Now Close\n\n";
		system("PAUSE");
		exit(0);
	}

	// Print The File And Ignore Asterisks
	while (file >> std::noskipws >> check)
	{
		if (check != '*')
		{
			std::cout << check;
		}
	}
}

// Assign The Next Question The Player Will Answer
void QuizInput::questionHandler()
{
	// String used to store the line numbers while parsing files.
	std::string line;
	// The Main Question File Numbered 1 - 50
	std::fstream populateFile("../Resources/Quiz/QuizPopulate.txt");
	// The File Used To Remove Questions As They Are Selected
	std::ofstream removalFile("../Resources/Quiz/QuizPopulateInSession.txt");

	// If Question Number = 0 Populate The Questions
	if (Q_num == 0)
	{
		// Open File
		std::fstream questionBackup("../Resources/Quiz/QuizPopulate-BACKUP.txt");
		// If File Does Not Exist Then Create A Replacement And Kick The Player Back To The Menu
		if (!questionBackup.is_open())
		{
			std::ofstream backupFix("../Resources/Quiz/QuizBackupPopulator.txt");
			for (int i = 1; i <= 50; i++)
			{
				backupFix << i << std::endl;
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
		// Create File
		std::ofstream reloadFile("../Resources/Quiz/QuizBuffer.txt");

		// While Parsing File
		while (getline(questionBackup, line))
		{
			// If The Line Number Is Greater Than 0 Then Create A New Line And Print Line
			if (std::stoi(line) > 0)
				reloadFile << std::endl << line;
			else
			{
				// If The Line Number Is 0 Then Print Line And Create A New Line
				reloadFile << line << std::endl;
			}
		}
		// Close All Text Files
		questionBackup.close();
		reloadFile.close();
		populateFile.close();
		// Remove Populate File And Replace With New File
		std::remove("../Resources/Quiz/QuizPopulate.txt");
		std::rename("../Resources/Quiz/QuizBuffer.txt", "../Resources/Quiz/QuizPopulate.txt");
		//Return To The Beginning Of The Populate File
		populateFile.clear();
		populateFile.seekg(0);
	}

	// If File Is Not Open, Open It
	if (!populateFile.is_open())
	{
		populateFile.open("../Resources/Quiz/QuizPopulate.txt");
	}
	// Generate Random Numbers
	srand((time(0)));
	// Int To Store Line Number
	int lineNum = 0;
	// String For Line Up For Deletion
	std::string deleteLine;
	// Vector To Store Remaining Lines
	std::vector<std::string> inSessionLines;
	// Int To Store Random Number
	int random = 0;
	// Int To Store A Random Entry In The Vector
	int randomEntry = 0;
	// Set Finish Bool To False
	finish = false;

	// Parse File
	while (getline(populateFile, line))
	{
		// Increase Line Number
		lineNum++;
		// Pass Line Number Into Iterator
		inSessionLines.push_back(line);
	}

	// If QuizInSession Is Not At End Of File
	if (!removalFile.eof())
	{
		// Bool Populated = true
		bool populated = true;
		// If Vector Is Empty Then Finish The Quiz
		if (inSessionLines.size() == 0)
		{
			finish = true;
			return;
		}
		else
		{
			//Otherwise Calculate A Random Number By Generating A Random Number Limited By The Vectors Size
			random = rand() % inSessionLines.size();
		}
		// Set Random Entry To The Line Number Located In The Vector
		randomEntry = std::stoi(inSessionLines[random]);
		if (populated)
			if (randomEntry == 0)
			{
				// If Random Entry Is 0 Then Regenerate It.
				random = rand() % inSessionLines.size();
				randomEntry = std::stoi(inSessionLines[random]);
			}
	}
	// Q_Num = The Results Of RandomEntry
	Q_num = randomEntry;
	// Return File To Beginning
	populateFile.clear();
	populateFile.seekg(0);
	lineNum = 0;
	// Parse Through File Again
	while (getline(populateFile, line))
	{
		//Add 1 To LineNum then use LineNum
		++lineNum;
		// If The LineNumber = Random + 1 Then Delete That Line
		if (lineNum == random + 1)
		{
			deleteLine = line;
		}
		// If It Does Not Equal Then Print It
		if (line != deleteLine)
		{
			removalFile << line << std::endl;
		}
	}
	// Close Both Files And Then Replace The File
	populateFile.close();
	removalFile.close();
	std::remove("../Resources/Quiz/QuizPopulate.txt");
	std::rename("../Resources/Quiz/QuizPopulateInSession.txt", "../Resources/Quiz/QuizPopulate.txt");
}

// Handles The Answer For The User
void QuizInput::answerHandler(int input)
{
	// Open File
	std::fstream file("../Resources/Quiz/Questions/Inputs/Question" + std::to_string(Q_num) + ".txt");

	// I Had Issues With Setting The Int To Char. Setting The Char To 0 And Adding The Input Fixed This
	char inputChar = '0' + input;
	if (Q_num != 0)
	{
		// While Parsing The File Do Not Skip Whitespaces And Feed Chars Into Check
		while (file >> std::noskipws >> check)
		{
			// If Check Equals An Asterisk Check The Next Character
			if (check == '*')
			{
				// If The Next Character Is The Users Input They Are Correct
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
		//If They Are Not Correct Then Display Incorrect Message
		if (!correct)
		{
			system("CLS");
			std::cout << "Incorrect\n\n";
			system("PAUSE");
			system("CLS");
		}
		correct = false;
	}
	// Generate Next Question
	questionHandler();
	// Increment Question Counter
	Q_NumDisplay++;
	// Check If Quiz Is Finished
	if (finish)
	{
		// Check The Players Score If It Is High Enough Display Success Message, If It Is Too Low Display Failed Message
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
		// Reset The Players Score
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
		// Handle The Players Answer
		answerHandler(input);
		// If The Quiz Is Finished Or An Error is Encountered Return The Player To The Menu
		if (finish | error)
		{
			*question = new Menu(player);
			delete q;
			break;
		}
		// Create Move Player To Next Question
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
	default:
		system("CLS");
		std::cout << "Please Select A Valid Option...\n\n";
		std::cin.clear();
		system("PAUSE");
		system("CLS");
		break;
	}
}