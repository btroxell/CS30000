#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "One_Operand_Instr.h"
#include "Two_Operand_Instr.h"
#include "Instruction.h"
#include "HashTable.h"
#include "Source_Line.h"
#include <istream>
#include <sstream>

// TODO: probably want to change the table data structures to a list****probably going to change this to a vector

// TODO: Understand what the hell the optable does and if we can just couple the operand and the instruction together
// UPDATE 4/4/2018: Optab is used to look up mnemonic operation codes nd translate to machine language equivalent, literally the instruction dictionary
// Pass 1: OPTAB used to look up and validate operation codes in source program
// Pass 2: Translates the operation codes to machine language

//const Instruction OPTAB[26];
HashTable OPTAB;

// TODO: Probably need to relook at what the hell this does too, should just be the labels, instructions, operands?
// UPDATE 4/4/2018: SYMTAB keeps track and stores addresses that are assigned to labels
// Includes the name and value for each label in source program with flags to indicate errors such as a symbol defined in 2 different places
// this table may also contain other information about data area or instruction labeled, such as type and length, 
//std::vector*SYMTAB = {};
std::vector<Source_Line> SYMTAB;

void hex_to_binary(Instruction *instr)
{
	std::string binary;
	//int opcode_len = strlen(instr->opcode_hex);

	for (int i = 0; i < 2; i++)
	{
		switch (instr->opcode_hex_[i])
		{

		case '0': binary += "0000"; break;
		case '1': binary += "0001"; break;
		case '2': binary += "0010"; break;
		case '3': binary += "0011"; break;
		case '4': binary += "0100"; break;
		case '5': binary += "0101"; break;
		case '6': binary += "0110"; break;
		case '7': binary += "0111"; break;
		case '8': binary += "1000"; break;
		case '9': binary += "1001"; break;
		case 'A': binary += "1010"; break;
		case 'B': binary += "1011"; break;
		case 'C': binary += "1100"; break;
		case 'D': binary += "1101"; break;
		case 'E': binary += "1110"; break;
		case 'F': binary += "1111"; break;

		}
	}//end for

	instr->set_binary(binary);
}

/* 
4/24/18 Brandon Troxell:
This function works correctly and hashes everything from the first file
*/
void readOneOpInstructionFile(std::ifstream &my_file)
{
	std::string str_line;
	std::string str_mnemonic;
	std::string str_hex;
	std::string str_format;
	
	//int ctr = 0;

	//std::string test;

	while (!my_file.eof())
	{
		getline(my_file, str_line);

		//std::cout << str_line << std::endl;
		
		std::istringstream entire_line(str_line);

			
		getline(entire_line, str_mnemonic, ',');
		getline(entire_line, str_hex, ',');
		getline(entire_line, str_format, ' ');

		//test = str_mnemonic + " " + str_hex + " " + str_format;

		//std::cout << test << std::endl;

		One_Operand_Instr *new_instr = new One_Operand_Instr(str_mnemonic, str_hex, str_format);
		hex_to_binary(new_instr);
		OPTAB.addInstruction(*new_instr);
		//std::cout << "before hex to binary: " << new_instr->mnemonic_ + " " + new_instr->opcode_hex_ + " " + new_instr->format_ << std::endl;

		//std::cout << new_instr->opcode_hex_[0] << new_instr->opcode_hex_[1] << std::endl;
		
		//std::cout << "after hex to binary: " << new_instr->opcode_bin_ << std::endl;

	}
	
}

/*
4/24/18 Brandon Troxell:
This function works correctly and hashes everything from the first file
*/
void readTwoOpInstructionFile(std::ifstream &my_file)
{
	std::string str_line;
	std::string str_mnemonic;
	std::string str_hex;
	std::string str_format;


	while (!my_file.eof())
	{

		getline(my_file, str_line);

		std::istringstream entire_line(str_line);

		getline(entire_line, str_mnemonic, ',');
		getline(entire_line, str_hex, ',');
		getline(entire_line, str_format, ' ');

		Two_Operand_Instr *new_instr = new Two_Operand_Instr(str_mnemonic, str_hex, str_format);
		hex_to_binary(new_instr);
		OPTAB.addInstruction(*new_instr);

		
	}
}

/*
4/24/18 Brandon Troxell:
Converts decimal(int types) to hexadecimal

This makes it easier to convert values and should be universal
*/
std::string dec_to_hex(int dec)
{
	std::string hex_loc;
	std::stringstream hex;
	hex << std::hex << dec;
	hex_loc = hex.str();
	return hex_loc;
}


/*
4/24/18 Brandon Troxell:
Started working on the first pass algorithm straight from the book

TODO: Need to figure out a way to parse an instruction line, 
retrieve an instruction from the Hashtable(aka OPTABLE), 
create and initialize a new instruction with a newly created and initialized operand,
then store the instruction into a source_line object along with the calculated location, label, etc..
finish the first pass of the assembler and then continue to the object code pass(aka Pass 2)
*/
void Pass1(std::ifstream &my_file)
{
	std::string str_line;
	

	getline(my_file, str_line);
	// find() return npos() which will return -1
	if (str_line.find("START") != -1)
	{
		int LOCCTR = 0;
		Source_Line *start = new Source_Line(true, 0, dec_to_hex(LOCCTR));
	}
}

/*
4/24/18 Brandon Troxell:

Made it so it can read multiple files of source programs
and only initialize the instructions and create the OPTABLE 
everytime the program is ran
*/
int main(int argc, char * argv[])
{

	if (argc == 3)
	{
		std::ifstream instr1_file(argv[1]);
		std::ifstream instr2_file(argv[2]);

		readOneOpInstructionFile(instr1_file);
		readTwoOpInstructionFile(instr2_file);

		std::string str_input;
		char *c_input;

		bool keepgoing = true;

		while (keepgoing)
		{
			std::cout << "Load file to convert to object code: ";
			getline(std::cin, str_input);
			//std::cout << input << std::endl;
			//Load instructions here
			
			if (str_input.size() > 5)
			{
				std::cout << "file is: " << str_input << std::endl;
				const char *file_name = str_input.c_str();
				//c_input = str_input.c_str();
				std::cout << "after c_str(): " << file_name << std::endl;
				//std::cout << "file is: " << c_input << std::endl;
				std::ifstream source_file(file_name, std::ifstream::in);
				std::cout << "file was successfully loaded" << std::endl;
			}
			else {
				keepgoing = false;
			}
			
		}

	}
	else {
		std::cout << "Error reading files" << std::endl;
		return 0;
	}



}