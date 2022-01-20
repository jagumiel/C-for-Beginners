#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "doubleLinkedList.h"

int main(void){
	List * list = makelist();
	for(uint8_t i=2; i<7; i++){
		addNode(i, list);
	}
	closeList(list);
	printf("______List of Nodes:______\n");
	display(list);
	//setValues(list);
	printf("__________________________\n");
	deleteNode(4, list);
	display(list);
	printf("__________________________\n");
	deleteNode(2, list);
	display(list);
	printf("__________________________\n");
	deleteNode(6, list);
	display(list);
}
