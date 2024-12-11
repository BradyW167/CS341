all: A6

run: all
	./A6

A6: driver.o HashEntry.o Node.o LinkedNode.o LinkedList.o DoubleLinkedList.o HashTableArray.o HashTableCuckoo.o
	g++ driver.o HashEntry.o Node.o LinkedNode.o LinkedList.o DoubleLinkedList.o HashTableArray.o HashTableCuckoo.o -o A6

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

HashEntry.o: HashEntry.cpp
	g++ -c HashEntry.cpp -o HashEntry.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

DoubleLinkedList.o: DoubleLinkedList.cpp
	g++ -c DoubleLinkedList.cpp -o DoubleLinkedList.o

HashTableArray.o: HashTableArray.cpp
	g++ -c HashTableArray.cpp -o HashTableArray.o

HashTableCuckoo.o: HashTableCuckoo.cpp
	g++ -c HashTableCuckoo.cpp -o HashTableCuckoo.o

clean:
	rm -rf *.o A6 A6.exe
