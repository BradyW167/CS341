//#include "dictionary.h"
#include "set.h"
#include "bitarray.h"

#include <string>
#include <iostream>

int main(){
	std::string input = "brady";
	BitArray a(input, input.length());

	/* Loop for each byte (character)
	for(int i = 0; i < a.bytes(); i++){
		std::cout << "|";
		for(int j = 7; j >= 0; j--){
			std::cout << a.get(i * 8 + j);
		}
		std::cout << "|" << std::endl;
	}*/

	a.print();

	std::cout << "0th bit Set: " << a.get(0) << std::endl;

	std::cout << "1th bit Set: " << a.get(1) << std::endl;

	std::cout << "Character including position 1 '" << a.get8(1) << "'" << std::endl;

	a.set(9, 1);
	a.set(10, 0);
	a.set(12, 0);

	std::cout << "Character including position 1 '" << a.get8(1) << "'" << std::endl;

	a.print();

	a.complement();

	a.print();

	a.clear();

	a.print();

	return 0;
}
