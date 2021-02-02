/*
 * terminalReader.c
 *
 *  Created on: 1 feb. 2021
 *      Author: jagumiel
 */


#include <stdio.h>

int main(){
	char str[100];
	int i;

	printf("Introduce a value:\n");
	scanf("%d %s", &i, str);

	printf("You have introduced the number: %d and the string %s\n", i, str);

	return 0;
}
