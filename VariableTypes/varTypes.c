/*
 * varTypes.c
 *
 *  Created on: 1 feb. 2021
 *      Author: jagumiel
 */


#include <stdio.h>
#include <stdbool.h>

int main(){
	//Booleans
	_Bool 	myBool1 = 1; 					//C89 form of boolean expression.
	bool 	myBool2 = true; 				//C99 form of boolean expression. Needs <stdbool.h> library.

	//Numeric
	int 		num1 = 127;					//Integer. Natural size.
	float 		num2 = 12.1268;				//Floating point. Single-precision.
	double 		num3 = 551.23496465485;		//Floating point. Double-precision.
	double 		num4 = 551.23496465485e+11; //Allows to use scientific notation.
	short		num5 = 37;					//Uses less bits than an standard int. Useful to save memory (i.e., in embedded devices).
	long		num6 = 69135;				//Allows to represent bigger numbers than int. Uses more memory.
	long long 	num7 = 21375238534;			//Allows even larger numbers than long.
	long double num8 = 23424234e+25;		//Same applied to double types.
	signed int 	num9 = -5;					//Just makes the possible negative values explicit.
	unsigned counter = 3;					//Used when only positive values are possible (i.e., a counter).

	//Enums: Allows to define and specify the valid values that could be stored into that variable.
	enum primaryColor {red, yellow, blue};	//Declares the options allowed for type primary color.
	enum primaryColor myColor, usersColor;	//Declares 2 variables of type primaryColor.
	myColor=red;
	usersColor=yellow;
	enum month {January, February, March, April, May, June, July, August, September, October, November, December};
	enum month thisMonth=1;					//Compiler treats enumeration identifiers as integer constants. February=1. C starts to count from zero.

	//Char
	char vowel		= 'A';
	char consonant	= 'B';
	char symbol		= ';';
	char byASCII	= 65;					//Poor style. Selects the character in the 65th position from the ASCII table.

	//Escape characters
	char newLine 		= '\n';
	char backSpace 		= '\b';
	char carriageReturn = '\r';
	char hTab 			= '\t';
	char vTab 			= '\v';
	char singleQuote 	= '\'';
	char questionMark 	= '\?';

	//Print different types of variable
	printf ("num1 = %i\n", num1);	//Represents an integer.
	printf ("num2 = %f\n", num2);	//Represents a float.
	printf ("num2 = %2.f\n", num2);	//Represents a float.
	printf ("num2 = %.2f\n", num2);	//Represents a float.
	printf ("num3 = %e\n", num3);	//Represents a double.
	printf ("num3 = %g\n", num3);	//Represents a double. Different format.
	printf ("num4 = %e\n", num4);
	printf ("num5 = %hi\n", num5);
	printf ("num6 = %li\n", num6);
	printf ("num7 = %lli\n", num7);
	printf ("num8 = %Lg\n", num8);
	printf ("num9 = %i\n", num9);
	printf ("counter = %u\n", counter);
	printf ("vowel= %c\n", vowel);	//Represents a character.
	printf ("Bool1= %i\n", myBool1);



	return 0;
}
