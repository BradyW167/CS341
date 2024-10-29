#include <fstream>
#include <sstream>
#include "student.h"

int main(){
	// Read input file
	std::ifstream inputFile("students.txt");

	std::string line;

	// Declare array of students for sorting
	Student students[30];
	int count; // For index entry into array
	
	// Check if file opened successfully
	if(inputFile.is_open()){
		std::cout << "*** Welcome to the GPA Calculator ***" << std::endl;
	
		// Loop through input file by line
		while(std::getline(inputFile, line)){
			// Declare instance variables
			std::string id, grade, cred;
			
			
			// Read individual lines
			std::stringstream ss(line);
			
			// Set instance variables
			std::getline(ss, id, ' ');
			std::getline(ss, grade, ' ');
			std::getline(ss, cred);
			
			// Create instance of student
			Student s(id, std::stoi(grade), std::stoi(cred));

			// Add student to array
			students[count] = s;
			// Print student from object methods
			s.printInfo();
			
			// Increment for next index entry into array
			count++;
		}

		// Key to track highest gpa
		int key;

		// Separates sorted values by starting loop after them index-wise
		int startindex = 1;

		// Selection sort algorithm based on gpa
		for(int i = startindex; i < 30; i++){
			// Compare gpa of two adjacent index students
			if(students[i-1].getGpa() < students[i].getGpa()){
				key = i-1;
			}
			startindex++;
		}

		// Swap highest gpa student to front of array
		swap(key, startindex-1);

		inputFile.close();
	}else{
		std::cout << "File could not be opened" << std::endl;
	}
	std::cin.get();
	return 0;
}

void swap(Student s[], int index1, int index2) {
    if (index1 == index2) {
        return;
    }

    Student temp = s[index1];
    s[index1] = s[index2];
    s[index2] = temp;
}
