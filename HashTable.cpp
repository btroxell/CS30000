#include "HashTable.h"

/*
* TODO: Change all the "wordItem" types to Instruction
* UPDATE 4/4/2018: DONE
*/
HashTable::HashTable(void) {

	for (int i = 0; i<tableSize; i++) { //for loop to initialize the hashtable

		table[i] = new instrNode; //gives the index of the hashtable a new worditem
		table[i]->instr.mnemonic_ = "nil"; //default value for the an unhashed spot
		table[i]->next = NULL; //gives the pointer to point at null
	}//end for

}//end hash constructor

/*
* TODO: 1. Change the way lookup works so it matches the function declaration in the header file
* 2. Since Instruction has a word, theWord variable will be the Instruction's mnemonic
* UPDATE 4/4/2018: DONE
*/
bool HashTable::lookup(Instruction myinstr) { //lookup function that takes the index given by the hash function and the word entered by the user

	int index = this->hashFunc(myinstr); //hash instruction to find index for lookup
											   //cout << index << endl;
	bool inBucket = false; //boolean variable

	instrNode* instrPtr = table[index]; //worditem pointer that points to the certain index

	int N = myinstr.mnemonic_.length(); //store the length of the word in a variable
	//cout << "length of word = " << N << endl;

	int i;// counter variable

	//UPDAT: (4/15/2018) Rewrote the actual lookup so it matches the logical functionality a little better.
	while (instrPtr != NULL && inBucket == false) {
		if (instrPtr->instr.mnemonic_.length() != N) { //if length of mnemonic does not match, move on to the next instruction
			instrPtr = instrPtr->next;
		}
		else {
			for (i = 0; i < N; i++) {
				if (myinstr.mnemonic_[i] != instrPtr->instr.mnemonic_[i]) { //if one character does not match, move on to the next instruction.
					i = N; //sets the condition to exit the for loop
					instrPtr = instrPtr->next;
				}
				else if (i == N - 1 && myinstr.mnemonic_[i] == instrPtr->instr.mnemonic_[i]) { //if all characters match, instruction is in the table
					inBucket = true;
				}
			}
		}
	}

	/*
	for (i = 0; i<N; i++) { //for loop to iterate through the characters in the string entered and the string stored in the list
		while (instrPtr != NULL) {//while there are things in the list
			if (myinstr.mnemonic_[i + 1] == instrPtr->instr.mnemonic_[i + 1]) {//conditional statement that compares letter by letter
				inBucket = true; //if the amount of letters in the user entered word is in any of the words in the list, then the bool var is true
				std::cout << instrPtr->instr.mnemonic_ << std::endl;//show word that matches users word
				instrPtr = instrPtr->next;//point to the next word and check

			}//end if
			else {
				instrPtr = instrPtr->next; //if none of the letters match with the users then go to next word
			}//end else
		}//end while

	}//end for
	*/

	if (inBucket == true) {
		std::cout << "$ True" << std::endl; //show true if there are words in bucket that match
	}
	else {
		std::cout << "$ False" << std::endl; //show false if not
	}
	return inBucket;
}//end lookup function


/*
TODO: This function needs to match function declaration with the parameters, so instead of key it will be the
Instructions mnemonic
UPDATE 4/4/2018: DONE
*/
int HashTable::hashFunc(Instruction key) {//hash function definition

	int index = (int)key.mnemonic_[0];//hash goes by the ASCII value of the first letter of the word(casts the character to int)

	index = index % tableSize;//index gets updated to the ASCII value of the first letter of the word and mods it by the table size
							  //ensures that any new word added can be hashed and added to the hash table if it has not been hashed

	return index;//allow to use this value in other places

}//end hash function

/*
TODO: Match function declaration and work with the Instructions mnemonic
*/
void HashTable::addInstruction(Instruction myinstr) {

	int index = hashFunc(myinstr);//index variable of hashtable that hashes the word passed through

	if (table[index]->instr.mnemonic_ == "nil") {//conditional statement if the word in the index does not contain anything of the value of the hashed word

		table[index]->instr = myinstr;//then store the word in to that index of the hashtable

	}//end if statement
	else {//if the index is not empty then else conditional

		instrNode* indexPtr = table[index];//word item pointer that points to the hashtable
		instrNode* newWdPtr = new instrNode;//creates a new wordItem that has a pointer to it
		newWdPtr->instr = myinstr;//takes the added word and places the word in there
		newWdPtr->next = NULL;//places the pointer to null

		while (indexPtr->next != NULL) {//traverse through the list and if the next pointer is not pointing to null

			indexPtr = indexPtr->next;//update the index pointer to next

		}//end while

		indexPtr->next = newWdPtr;//if it is null then the indexPtr which points to the hashtable index that points to the next word will point to the word

	}//end else

}//end add word function