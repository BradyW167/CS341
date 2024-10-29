#include <string>
#include <iostream>

class Student{
	public:
		Student();
		Student(std::string id, int grade, int cred);
		~Student();
		
		std::string getId();
		int getGradePoints();
		int getCred();
		double getGpa();
		char getLetterGrade();

		void printInfo();
	private:
		std::string id_;
		int gradePoints, creditHours;
		double gpa;
		char letterGrade;

		char calculateLetterGrade(double num);
};
