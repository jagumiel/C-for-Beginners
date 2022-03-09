#include "doubleLinkedList.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



/* Creates a new node. Next and prev pointers will be setted on "addNode" function. */
Node * createnode(uint8_t data){
	Node * newNode = malloc(sizeof(Node));
	if (!newNode) {
    	return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

/* Creates the structure list. */
List * makelist(){
	List * list = malloc(sizeof(List));
	if (!list) {
		return NULL;
	}
	list->head = NULL;
	return list;
}

/* Adds a new node to the list. Updates the new node with the pointer to the preceding node.
 * The new node is the last, so the list's "tail value is updated too */
void addNode(uint8_t data, List * list){
	Node * current = NULL;
	Node * nextNode = NULL;
	if(list->head == NULL){
		list->head = createnode(data);
	} else {
		current = list->head;
		while (current->next!=NULL){
			current = current->next;
		}
		nextNode = createnode(data);
		current->next = nextNode;
		list->tail=nextNode;
		nextNode->prev=current;
	}
}

/* It is a circular double linked list. The last node and the first node must be referenced mutually.
 * When the list have been filled, it is necessary to close it.
 * This means that tail's next value is the head of the list and head's previous value is the tail. */
void closeList(List * list){
	Node * firstNode = NULL;
	Node * lastNode = NULL;
	if(list->head != NULL){
		firstNode = list->head;
		lastNode = list->tail;
		lastNode->next = list->head;
		firstNode->prev = list->tail;
	}
}


/* Testing proposes. It prints info about the list's nodes and their content. */
void display(List * list) {
	Node * current = list->head;
	if(list->head == NULL){
		return;
	}

	do {
		printf("Node: %d. Prev: %d. Next: %d.\n", current->data, current->prev->data, current->next->data);
		current = current->next;
	} while(current != list->head);
}

/* Deletes the node with a concrete parametrized value. */
void deleteNode(uint8_t data, List * list){
	Node * current = list->head;
	Node * previous = current;
	while(current != NULL){
		if(current->data == data){
			previous->next = current->next;
			current->next->prev=previous;
			if(current == list->head){
				list->head = current->next;
				list->head->prev=list->tail;
				list->tail->next=list->head; /* I think this is necessary too. I am not sure if this changes when head changes automatically. */
			}else if(current == list->head){
				list->tail = current->prev;
				list->tail->next=list->head;
				list->head->prev=list->tail; /* I think this is necessary too. I am not sure if this changes when head changes automatically. */
			}
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}


/* Deletes the nodes and destroys the list.
 * The list is just an structure with two pointers.
 * If the only list was deleted, nodes would remain in memory.
 * It is necessary to delete the nodes first and then the list structure. */
void destroy(List * list){
	Node * current = list->head;
	Node * next = current;
	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	free(list);
}


/* Function generated for other proposes. */
void setValues(List * list) {
	uint8_t var1, var2, var3, var4, var5;
	Node * current = list->head;
	if(list->head == NULL)
		return;

	for(int i=0; i<4; i++){
		while(current!=NULL) {
			var1=current->data;
			var2=current->next->data;
			var3=current->next->next->data;
			var4=current->next->next->next->data;
			var5=current->next->next->next->next->data;
			current = current->next;
			printf("Var1: %d, Var2: %d, Var3: %d, Var4: %d, Var5: %d\n", var1, var2, var3, var4, var5);
			if(current == list->head){
				break;
			}
		}
	}
}

void setHeadAndTail(List * list, uint8_t firstValue){
	Node * current = list->head;
	if(current!=NULL){
		while(current->next!=list->head){
			current=current->next;
			if(current->data==firstValue){
				list->head=current;
				list->tail=current->prev;
			}
		}
	}
}


//void reverse(List * list){
//  Node * reversed = NULL;
//  Node * current = list->head;
//  Node * temp = NULL;
//  while(current != NULL){
//    temp = current;
//    current = current->next;
//    temp->next = reversed;
//    reversed = temp;
//  }
//  list->head = reversed;
//}
////Reversing the entire list by changing the direction of link from forward to backward using two pointers
//void reverse_using_two_pointers(List *list){
//    Node *previous = NULL;
//    while (list->head)
//    {
//        Node *next_node = list->head->next; //pouint8_ts to second node in list
//        list->head->next = previous;//at initial making head as NULL
//        previous = list->head;//changing the next pointer direction as to pouint8_t backward node
//        list->head = next_node; //moving forward by next node
//    }
//    list->head=previous;
//}
