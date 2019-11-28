/// <summary>
/// Author: Aaron O Neill
/// Time Taken:  1 hour 
/// @Brief: Simple program to output hello world to the console screen
/// then end with input from the user
/// </summary>
#include "Output.h"

int main()
{
	srand(static_cast<unsigned>(time(nullptr))); // set the seed to a random number based on time
	Output hello; // create class to output message
	hello.world(); // call function :D
	std::cin.get(); // stall the program until getting user input
	return 1; // return successful
}