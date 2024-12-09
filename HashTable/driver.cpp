#include <iostream>
#include <string>

#include "DoubleLinkedList.h"
#include "LinkedList.h"

int main(){
	DoubleLinkedList* dlist = new DoubleLinkedList();
	
	dlist->insert(HashEntry(2, 6));
	dlist->insert(HashEntry(5, 295));
	dlist->insert(HashEntry(7, 23));

	dlist->printList();

	delete dlist;

	return 0;
}
