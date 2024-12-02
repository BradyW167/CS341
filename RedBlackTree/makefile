all: A5

run: all
	./A5

A5: driver.o Node.o TreeNode.o BST.o RBT.o
	g++ driver.o Node.o TreeNode.o BST.o RBT.o -o A5

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o

BST.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BST.o

RBT.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RBT.o

clean:
	rm -rf *.o A5.exe A5
