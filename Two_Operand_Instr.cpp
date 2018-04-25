#include "Two_Operand_Instr.h"

//need to change var name
Two_Operand_Instr::Two_Operand_Instr(void)
	: Instruction(), operand1_(new Operand()), operand2_(new Operand())
{

}

Two_Operand_Instr::Two_Operand_Instr(std::string m, std::string hex, std::string form)
	: Instruction(m, hex, form)
{

}

Two_Operand_Instr::Two_Operand_Instr(std::string m, std::string hex, std::string form, Operand *op1, Operand *op2)
	: Instruction(m, hex, form), operand1_(op1), operand2_(op2)
{

}

Two_Operand_Instr::~Two_Operand_Instr(void)
{

}

Operand *Two_Operand_Instr::get_operand1()
{
	return operand1_;
}

Operand *Two_Operand_Instr::get_operand2()
{
	return operand2_;
}

void Two_Operand_Instr::set_operand1(Operand *op)
{
	this->operand1_ = op;
}

void Two_Operand_Instr::set_operand2(Operand *op)
{
	this->operand2_ = op;
}
