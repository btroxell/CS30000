#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <string>
#include <iostream>

class Instruction 
{
public:

	Instruction(void);
	Instruction(std::string m, std::string hex, std::string form);
	~Instruction(void);

	void set_binary(std::string bin);

	std::string mnemonic_;
	std::string opcode_hex_;
	std::string opcode_bin_;
	std::string format_;

};


#endif