all: bit.exe run

bit.exe: bitarray.o driver.o 
	g++ bitarray.o driver.o -o bit.exe

bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o
	
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

#dictionary.o: dictionary.cpp
#	g++ -c dictionary.cpp -o dictionary.o

#set.o: set.cpp
#	g++ -c set.cpp -o set.o

clean:
	rm -rf *.o bit.exe

run:
	./bit.exe
