#include <string>
#include <iostream>

#include "LinkedList.h"
#include "DoubleLinkedList.h"

int main(){
	LinkedList* list = new LinkedList();
	
	list->insert(15);
	list->insert(7);
	list->insert(10);

	list->printList();

  	LinkedList* list2 = list;

  	list2->printList();

	delete list;

	DoubleLinkedList* dlist = new DoubleLinkedList();
	
	dlist->insertLinkedNode(dlist->getHead(), 10);
	dlist->insertLinkedNode(dlist->getTail(),7);
	dlist->insertLinkedNode(dlist->getTail(), 12);

	dlist->printList();

	delete dlist;

	return 0;
}
