#include <iostream>
#include <string>
#include <vector>

std::vector<char> duplicateList(std::string s){
	int bitty(0);
	std::vector<char> duplicates;

	for(int i = 0; i < s.length(); i++){
		int charvalue = s[i] - 'a';

		std::cout << s[i] << " - 'a': " << s[i] - 'a' << std::endl;

		if((bitty & (1 << charvalue)) > 0){
			duplicates.push_back(s[i]);
		}
		bitty |= (1 << charvalue);
	}
	return duplicates;
}

int main(){
	std::vector<char> duplicates;
	std::string test = "butler bulldogs";
	duplicates = duplicateList(test);

	for(char letter : duplicates){
		std::cout << letter << " ";
	}

	std::cout << std::endl;
	return 0;
}
