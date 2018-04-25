#ifndef _TWO_OPERAND_INSTR_H_
#define _TWO_OPERAND_INSTR_H_

#include "Instruction.h"
#include "Operand.h"

/*
4/24/18 Brandon Troxell:

TODO: Need to create a copy constructor for instructions so that when the
HashTable getInstruction() returns an instruction, we can copy it and initialize
an operand to be able to pass to a Source_Line object
*/
class Two_Operand_Instr : public Instruction
{
public:

	Two_Operand_Instr(void);
	Two_Operand_Instr(std::string m, std::string hex, std::string bin);
	Two_Operand_Instr(std::string m, std::string hex, std::string bin, Operand *op1, Operand *op2);
	~Two_Operand_Instr(void);

	Operand *get_operand1();
	Operand *get_operand2();

	void set_operand1(Operand *op);
	void set_operand2(Operand *op);

	// Operand should be its own class so it can have the register or operand name and location
	Operand *operand1_;
	Operand *operand2_;
};


#endif // !_TWO_OPERAND_INSTR_H_