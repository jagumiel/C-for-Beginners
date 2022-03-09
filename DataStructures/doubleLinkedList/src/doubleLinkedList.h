#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

/* -==== Libraries: ====- */
#include <stdint.h>

/* -==== Structs: ====- */
typedef struct node Node;
typedef struct list List;

/* Double Linked Node: */
struct node {
	uint8_t data;
	struct node * next;
	struct node * prev;
};

/* List. It stores pointers to the first and the last node: */
struct list {
	Node * head;
	Node * tail;
};


/* -==== Methods: ====- */
List * makelist();
void addNode(uint8_t data, List * list);
void closeList(List * list);
void deleteNode(uint8_t data, List * list);
void destroy(List * list);
void display(List * list);
void setValues(List * list);
void setHeadAndTail(List * list, uint8_t firstValue);



#endif
