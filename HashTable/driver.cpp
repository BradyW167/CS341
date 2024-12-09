#include <iostream>
#include <string>

#include "DoubleLinkedList.h"
#include "LinkedList.h"

int main(){
	DoubleLinkedList* dll = new DoubleLinkedList();
	
	dll->insert(HashEntry(2, 6));
	dll->insert(HashEntry(5, 295));
	dll->insert(HashEntry(7, 23));

	dll->printList();

	delete dll;

	return 0;
}
