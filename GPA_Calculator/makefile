gpa.exe: student.o driver.o
	g++ student.o driver.o -o gpa.exe

student.o: student.cpp
	g++ -c student.cpp -o student.o
	
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

clean:
	rm -rf *.o gpa.exe

run:
	gpa.exe
