#include "Output.h"

/// <summary>
/// @brief Default Constructor
/// </summary>
Output::Output() : 
	m_message("Hello World"),
	m_stdOut(GetStdHandle(STD_OUTPUT_HANDLE)),
	m_messagePos(COORD{60,20})
{
	HWND console = GetConsoleWindow();
	MoveWindow(console, 100, 100, 1200, 800, true); // move and resize the window
}

/// <summary>
/// @brief Default Deconstructor
/// </summary>
Output::~Output()
{
	std::cout << "Output Deconstructed\n";
}

/// <summary>
/// @brief Outputs random values onto the screen until the Hello World message is finally displayed fully
/// </summary>
void Output::world()
{
	SetConsoleTextAttribute(m_stdOut, WORD{ 11 });
	std::cout << "#####################################\n";
	std::cout << "Generating Message\n";
	std::cout << "#####################################\n";
	int messageIndex{ 0 };
	int turn{ 0 };
	while (messageIndex < m_message.length()) // while the whole message has not been outputted
	{
		if (turn % 500 == 0)
		{ // small chance it will output the message
			SetConsoleCursorPosition(m_stdOut, m_messagePos); // move the cursor to the position
			m_messagePos.X++; // increase the message position
			SetConsoleTextAttribute(m_stdOut, FOREGROUND_GREEN); // make the message be green
			std::cout << m_message.at(messageIndex);
			messageIndex++; // increase the number of outputted messages
		}
		else
		{
			COORD randPos{ rand() % 140, rand() % 40 + 4 }; // choose a random position on the screen 
			if (randPos.Y == m_messagePos.Y)
			{// check if the random character is on the same level as the message
				if (randPos.X > m_messagePos.X - (messageIndex+1) && randPos.X < m_messagePos.X + m_message.length() - messageIndex)
				{ // if its going to overwrite a character move it down a level
					randPos.Y++;
				}
			}
			SetConsoleCursorPosition(m_stdOut, randPos); // set the cursor to a random position
			SetConsoleTextAttribute(m_stdOut, FOREGROUND_RED); // make the wrong message be red
			char out = rand() % 4 + 35; // generate random character 
			std::cout << out; // output the random character
		}
		Sleep(1); // pause the program for a fraction of time
		turn++;
	}
	COORD finishPos{ 0,45 };
	SetConsoleCursorPosition(m_stdOut, finishPos); // set the cursor to the bottom of all the text
	WORD color{15};
	SetConsoleTextAttribute(m_stdOut, color);
}
