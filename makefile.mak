assembler: main.o HashTable.o Source_Line.o One_Operand_Instr.o Two_Operand_Instr.o Instruction.o Operand.o
	g++ Operand.o Instruction.o One_Operand_Instr.o Two_Operand_Instr.o Source_Line.o HashTable.o main.o -o assembler
main.o: main.cpp HashTable.o Source_Line.o One_Operand_Instr.o Two_Operand_Instr.o Instruction.o Operand.o     
	g++ -c main.cpp
Hashtable.o: HashTable.cpp One_Operand_Instr.o Two_Operand_Instr.o Instruction.o 
	g++ -c HashTable.cpp
Source_Line.o: Source_Line.cpp One_Operand_Instr.o Two_Operand_Instr.o Instruction.o
	g++ -c Source_Line.cpp
One_Operand_Instr.o: One_Operand_Instr.cpp Instruction.o
	g++ -c One_Operand_Instr.cpp
Two_Operand_Instr.o: Two_Operand_Instr.cpp Instruction.o
	g++ -c Two_Operand_Instr.cpp
Instruction.o: Instruction.cpp
	g++ -c Instruction.cpp
Operand.o: Operand.cpp
	g++ -c Operand.cpp
clean:
	rm -f *.o assembler.out