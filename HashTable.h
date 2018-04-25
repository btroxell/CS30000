#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include "Instruction.h"



/*
4/24/18 Brandon Troxell:

TODO: Need to create a getInstruction() function to return an instruction from the table
*/
class HashTable {

private:

	static const int tableSize = 26; //initialize the tablesize that is

	struct  instrNode { //create a struct to enable making a linked list
		Instruction instr; //has data type string which stores the word
		instrNode* next; //a pointer to point to the next word#include <string>

	};

	instrNode* table[tableSize]; //creates a array of type worditem pointer that points to the array

public:

	HashTable(void);//no args constuctor
	void addInstruction(Instruction instr); //addword function
	Instruction getInstruction(Instruction instr);
	bool lookup(Instruction instr); //lookup function returns boolean
	int hashFunc(Instruction key); //hash function that returns an int

};


#endif // !_HASHTABLE_H_

