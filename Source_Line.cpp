#include "Source_Line.h"

Source_Line::Source_Line(void)
	: isStart_(false), location_(0), hex_location_("0"), label_("null"), instr_(NULL)
{

}
// 4/24/18 Brandon Troxell:
// Created for the START line
Source_Line::Source_Line(bool start, int loc, std::string str_loc)
	: isStart_(start), location_(loc), hex_location_(str_loc), label_("null"), instr_(NULL)
{

}

// 4/24/18 Brandon Troxell:
// Created for the START line that has a label
Source_Line::Source_Line(bool start, int loc, std::string str_loc, std::string lab)
	: isStart_(start), location_(loc), hex_location_(str_loc), label_(lab), instr_(NULL)
{

}

// 4/24/18 Brandon Troxell:
// Other constructors are for all other types of instructions that have location and a label or not
Source_Line::Source_Line(bool start, int loc, std::string str_loc, Instruction *instr)
	: isStart_(start), location_(loc), hex_location_(str_loc), label_("null"), instr_(instr)
{

}

Source_Line::Source_Line(bool start, int loc, std::string str_loc, std::string lab, Instruction *instr)
	: isStart_(start), location_(loc), hex_location_(str_loc), label_(lab), instr_(instr)
{

}

Source_Line::~Source_Line(void)
{

}

bool Source_Line::isStart()
{
	return this->isStart_;
}