
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include <sstream>

// Returns int
// Prints error message if not int 
// Pass prompt as string
int getIntFromUser(const std::string& prompt);

// Returns int in the specified min-max range. 
// Prints error message if not int or not in range
int getIntInRangeFromUser(int min, int max);

#endif