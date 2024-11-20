all: bit

run: all
	./bit

bit: driver.o bitarray.o set.o dictionary.o
	g++ driver.o bitarray.o set.o dictionary.o -o bit

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o

set.o: set.cpp
	g++ -c set.cpp -o set.o

dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -o dictionary.o

clean:
	rm -rf *.o bit
