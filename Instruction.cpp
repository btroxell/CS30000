#include "Instruction.h"

Instruction::Instruction(void)
	: mnemonic_("somethin"), opcode_hex_("00"), opcode_bin_("00000000")
{

}

Instruction::Instruction(std::string m, std::string hex, std::string form)
	: mnemonic_(m), opcode_hex_(hex), format_(form)
{

}

Instruction::~Instruction(void)
{
	//std::cout << "Instruction has been deconstructed" << std::endl;
}

void Instruction::set_binary(std::string bin)
{
	this->opcode_bin_ = bin;
}