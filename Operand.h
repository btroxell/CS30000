#ifndef _OPERAND_H_
#define _OPERAND_H_

#include <string>
#include <iostream>

// Design Thought: Since there is an operand table, and to make it easier to implement the algorithm
// given in the book, probably should not couple an Operand with the Instruction but I will definitely 
// re-read the book and make sure
/*
4/24/18 Brandon Troxell:

Changed Variable Names
During implementation of Operand, loc_str should already be converted to hexadecimal 
using dec_to_hex() in main.cpp, similar to Source_Line object
*/
class Operand
{
public:

	Operand(void);
	Operand(std::string op_name, int loc, std::string loc_str);
	~Operand(void);

	std::string operand_name_;
	int dec_location_;
	std::string hex_location_;
	
};


#endif // !_OPERAND_H_

