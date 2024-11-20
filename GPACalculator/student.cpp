#include "student.h"
#include <iomanip>

// Default constructor
Student::Student(){
	id_ = "Unknown";
	gradePoints = 0;
	creditHours = 0;
	gpa = 0;
	letterGrade = '#';
}

// 
Student::Student(std::string id, int grade, int cred){
	id_ = id;
	gradePoints = grade;
	creditHours = cred;

	// Calculate gpa as a double with casting
	gpa = static_cast<double>(gradePoints) / creditHours;

	// Call method to get char type letter grade
	letterGrade = calculateLetterGrade(gpa);
}

Student::~Student(){}

std::string Student::getId(){
	return id_;
}

int Student::getGradePoints(){
	return gradePoints;
}

int Student::getCred(){
	return creditHours;
}

double Student::getGpa(){
	return gpa;
}

char Student::getLetterGrade(){
	return letterGrade;
}

void Student::printInfo(){
	std::cout << id_ << ": " << std::fixed << std::setprecision(2) << gpa << "	" << letterGrade << std::endl;
}

char Student::calculateLetterGrade(double num){
    if (num >= 0.0 && num < 1.7) {
       return 'D';
    } else if (num >= 1.7 && num < 2.7) {
       return 'C';
    } else if (num >= 2.7 && num < 3.7) {
       return 'B';
    } else if (num >= 3.7 && num < 4.0) {
       return 'A';
    } else {
       return 'E'; 
    }
}
