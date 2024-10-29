all: A4

run: all
	./A4

A4: driver.o node.o LinkedNode.o LinkedList.o
	g++ driver.o node.o LinkedNode.o LinkedList.o -o A4

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

node.o: node.cpp
	g++ -c node.cpp -o node.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

#DoubleLinkedList.o: DoubleLinkedList.cpp
#	g++ -c DoubleLinkedList.cpp -o DoubleLinkedList.o
	
clean:
	rm -rf *.o A4
