#include "One_Operand_Instr.h"

One_Operand_Instr::One_Operand_Instr(void)
	: operand_(new Operand())
{

}

One_Operand_Instr::One_Operand_Instr(std::string m, std::string hex, std::string form)
	: Instruction(m, hex, form)
{

}

One_Operand_Instr::One_Operand_Instr(std::string m, std::string hex, std::string form, Operand *op)
	: Instruction(m, hex, form), operand_(op)
{

}

One_Operand_Instr::~One_Operand_Instr(void)
{

}

Operand *One_Operand_Instr::get_operand()
{
	return operand_;
}

void One_Operand_Instr::set_operand(Operand *op)
{
	this->operand_ = op;
}