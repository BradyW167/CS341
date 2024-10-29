#include <string>
#include <iostream>

#include "LinkedNode.h"
#include "LinkedList.h"

int main(){
	LinkedList* list = new LinkedList();
	
	list->insert(15);
	list->insert(7);
	list->insert(10);

	list->printList();

	delete list;

	list = new LinkedList();

	list->insert();
	list->insert(12);
	list->insert();

	list->printList();
	return 0;
}
