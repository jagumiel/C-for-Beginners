#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

/* Libraries: */
#include <stdint.h>

/* Structs: */
typedef struct node Node;
typedef struct list List;


/* Methods: */
List * makelist();
void addNode(uint8_t data, List * list);
void closeList(List * list);
void deleteNode(uint8_t data, List * list);
void destroy(List * list);
void display(List * list);
void setValues(List * list);


#endif
