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

  LinkedList* list2 = list;

  list2->printList();

  delete list;
	return 0;
}
