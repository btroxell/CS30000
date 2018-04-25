#ifndef _SOURCE_LINE_H_
#define _SOURCE_LINE_H_

#include "Instruction.h"
#include <iostream>
#include <sstream>
#include <string>

/*
4/24/18 Brandon Troxell:

This class was created so we dont need to create and write to a intermediate file.
The idea is to have a vector of these Source_Lines that have their calculated location.

The only thing that may be confusing is the hex_location_ which will be a hexadecimal 
value of the location_ before the Source_Line is initialized in implementation.
So the str_loc will be the string of the location_ converted to hexadecimal by the dec_to_hex() in main.cpp
*/

class Source_Line
{
public:
	bool isStart_;
	int location_;
	std::string hex_location_;
	std::string label_;
	Instruction *instr_;

	Source_Line(void);
	Source_Line(bool start, int loc, std::string str_loc);
	Source_Line(bool start, int loc, std::string str_loc, std::string lab);
	Source_Line(bool start, int loc, std::string str_loc, Instruction *instr);
	Source_Line(bool start, int loc, std::string str_loc, std::string lab, Instruction *instr);
	~Source_Line(void);

	bool isStart();

};

#endif // !_SOURCE_LINE_H_
