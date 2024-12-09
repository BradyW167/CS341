// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling
#include "bitarray.h"
#include "set.h"
#include "dictionary.h"

#include <fstream>
#include <iostream>
#include <string>

int main(){
	std::string word1 = "brady";
	std::string word2 = "morgl";

	BitArray A(word1, word1.length());

	/* Loop for each byte (character)
	for(int i = 0; i < a.bytes(); i++){
		std::cout << "|";
		for(int j = 7; j >= 0; j--){
			std::cout << a.get(i * 8 + j);
		}
		std::cout << "|" << std::endl;
	}*/

	std::cout << "***** BITARRAY OPERATIONS *****" << std::endl;

	std::cout << "\nBitArray \"" << word1 << "\":" << std::endl;
	A.print();

	std::cout << "\n0th Bit Set: " << (A.get(0) ? "True" : "False") << std::endl;

	std::cout << "\n1th Bit Set: " << (A.get(1) ? "True" : "False") << std::endl;

	std::cout << "\nCharacter including position 8: '" << A.get8(8) << "'" << std::endl;
	std::cout << "\nCharacter including position 16: '" << A.get8(16) << "'" << std::endl;

	std::cout << "\nEditing array... " << std::endl;
	A.print();

	A.set(9, 0);
	A.set(10, 1);
	A.set(12, 0);
	A.set8('z',2);

	std::cout << "----------------------------------------------" << std::endl;
	A.print();

	std::cout << "\nCharacter including position 8: '" << A.get8(8) << "'" << std::endl;
	std::cout << "\nCharacter including position 16: '" << A.get8(16) << "'" << std::endl;

	// Change bitarray A to it's complement and print
	A.complement();
	A.print();

	// Change bitarray A to all 0s and print
	A.clear();
	A.print();

	std::cout << "\n***** SET OPERATIONS *****" << std::endl;

	Set C(word1, word1.length());
	Set D(word2, word2.length());

	C.getData().print();
	D.getData().print();

	std::cout << "\nSet C Cardinality: " <<  C.getCardinality() << std::endl;
	std::cout << "\nSet D Cardinality: " <<  D.getCardinality() << std::endl;

	C.setUnion(D);

	C.setIntersection(D);

	std::cout << "\n***** DICTIONARY OPERATIONS *****" << std::endl;

	Dictionary E("brady", 5);

	E.getData().print();

	std::cout << "\nRank: " << E.rank(39,1) << std::endl;
	std::cout << "\nRank (0-15): " << E.rank(15,1) << std::endl;

	std::cout << "\nRank Range(8-15): " << E.rank_range(8,15,1) << std::endl;
	std::cout << "\nRank Range(7-16): " << E.rank_range(7,16,1) << std::endl;

	std::cout << "\nSelect(4,1): " << E.select(4,1) << std::endl;

	std::cout << "\nSelect Range(5,10,2,1): " << E.select_range(5,10,2,1) << std::endl;
	std::cout << "\nSelect Range(2,7,2,0): " << E.select_range(2,7,2,0) << std::endl;

  std::ofstream outFile("output.txt");

  if (!outFile) {
      std::cerr << "Failed to open the file.\n";
      return 1;
  }

	E.printLookupTable(outFile);

	return 0;
}
