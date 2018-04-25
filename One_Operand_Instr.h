#ifndef _ONE_OPERAND_INSTR_H_
#define _ONE_OPERAND_INSTR_H_

#include "Instruction.h"
#include "Operand.h"

/*
4/24/18 Brandon Troxell:

TODO: Need to create a copy constructor for instructions so that when the
HashTable getInstruction() returns an instruction, we can copy it and initialize
an operand to be able to pass to a Source_Line object
*/
class One_Operand_Instr : public Instruction
{
public:

	One_Operand_Instr(void);
	One_Operand_Instr(std::string m, std::string hex, std::string form);
	One_Operand_Instr(std::string m, std::string hex, std::string form, Operand *op);
	~One_Operand_Instr(void);

	Operand *get_operand();
	void set_operand(Operand *op);

	// Operand should be its own class so it can have the register or operand name and location
	Operand * operand_;

};


#endif // !_ONE_OPERAND_INSTR_H_

