#include "Operand.h"

Operand::Operand(void)
	: operand_name_("r1"), dec_location_(0), hex_location_("0")
{

}

Operand::Operand(std::string op_name, int loc, std::string loc_str)
	: operand_name_(op_name), dec_location_(loc), hex_location_(loc_str)
{

}

Operand::~Operand(void)
{
	std::cout << "operand was deconstructed" << std::endl;
}


