#pragma once

#include <iostream>
#include <array>
#include <cstdlib>
#include <time.h>
#include <Windows.h>

class Output
{
	std::string m_message; // message I miss to output

	HANDLE m_stdOut; // output window

	COORD m_messagePos; // holds the current position of the message character

public: 
	Output();
	~Output();

	void world();
};

