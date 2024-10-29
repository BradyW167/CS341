// Bitwise Manipulation
//
// By: Dr. Ryan Rybarczyk

// Library to allow us to show bits...
#include <bitset>

#include <iostream>

int main()
{	
	unsigned int x = 15;	  
	unsigned int y = 87;	
	
	int z(0);

	z = x & y;             
	
	std::cout << std::bitset<8>(x) << std::endl;
	std::cout << std::bitset<8>(y) << std::endl;
	std::cout << "--------" << std::endl;
	std::cout << std::bitset<8>(z) << std::endl;
	std::cout << "Bitwise AND: " << z << std::endl;
	
	z = x | y; 
	
	std::cout << std::endl << std::endl << std::bitset<8>(x) << std::endl;
	std::cout << std::bitset<8>(y) << std::endl;
	std::cout << "--------" << std::endl;
	std::cout << std::bitset<8>(z) << std::endl;
	std::cout << "Bitwise OR: " << z << std::endl;
	
	z = x ^ y; 
	
	std::cout << std::endl << std::endl << std::bitset<8>(x) << std::endl;
	std::cout << std::bitset<8>(y) << std::endl;
	std::cout << "--------" << std::endl;
	std::cout << std::bitset<8>(z) << std::endl;
	std::cout << "Bitwise XOR: " << z << std::endl;
	
	z = ~x; 
	std::cout << std::endl << std::endl << std::bitset<8>(x) << std::endl;
	std::cout << "--------" << std::endl;	
	std::cout << std::bitset<8>(z) << std::endl;
	std::cout << "Bitwise 1’s Compliment: " << z << std::endl;

	unsigned int a = 1;	  	
	
	int b(0);

	b = a << 2;             
	
	std::cout << std::endl << std::endl << "Bitwise Left Shift: " << b << std::endl;
	std::cout << "Bitwise Left Shift: " << std::bitset<8>(b) << std::endl;
	
	b = b >> 2;
	
	std::cout << std::endl << std::endl << "Bitwise Right Shift: " << b << std::endl;
	std::cout << "Bitwise Right Shift: " << std::bitset<8>(b) << std::endl;
	
	return 0;
}
