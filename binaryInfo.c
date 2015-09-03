/*Laura Stalker
LS451494
lstalker@albany.edu
*/


#include <stdio.h>  /*Include standard i/o library*/
#include <stdlib.h>  /*To use exit function*/
#include <string.h>  /*Include the string library*/
#include "constants.h"  /*Header file with constants*/
#include "prototypes.h"  /*Header file with prototypes*/


/*A function that takes a FILE pointer as an argument, and returns nothing.
It is assumed that the FILE ptr is to a (binary) input file.  This function
reads triplets (of char, string, int) from the file and checks them against
previously read data, to find the length of te longest and shortest strings, 
and the largest and smallest ints.  It is assumed that the char represents 
the length of the string, which follows the char. After the string is a 
non-negative integer.  (It is assumed that if there is a next char in the 
file, then there will be a string and an int to follow.) After the entire 
has been read through, the function prints the length of te longest and 
shortest strings, and the largest and smallest ints to std out.
*/

void binaryInfo( FILE* inPtr){

	unsigned int num;  /*Integer after the string*/
	unsigned char len;  /*Length of the string*/
	char stringArray[ MAX_STRING_LENGTH];  /*Holds the string*/
	unsigned int shortString;  /*Length of shortest string in the file*/
	unsigned int longString;  /*Length of longest string in the file*/
	unsigned int minInt;  /*Smallest int in the file*/
	unsigned int maxInt;  /*Largest int in the file*/
	unsigned int length;  /*A variable to store char "len" in as an int*/
	length = 0;  /*Initialize variables*/
	shortString = MAX_STRING_LENGTH;  /*Initialize to longest string 
										we can expect*/ 
	longString = 0;  /*Initialize to 0*/
	minInt = MAX_INT;  /*Initialize to the largest int we could have*/
	maxInt = 0;  /*Initialize to smallest int we could have*/
	num = 0;  /*Initialize to 0*/

	/*While there are more triplets (length, string, number) to 
	read, read and store the values
	*/
	while( (fread( (void*) &len, sizeof( unsigned char), 1, inPtr)) == 1){
		length= len;  /*Save the char as an int*/
		fread( (void*) stringArray, 1, length, inPtr);
		fread( (void*) &num, sizeof(int), 1, inPtr);

		/*Compare the values read to those decided to be the longest
		and shortest word length, and the largest and smallest ints.
		If they are larger than the largest(or smaller than the smallest) 
		corresponding value, replace the max/min value with the current 
		value.
		*/
		if( len > longString){
			longString = len;
		}
		if( len < shortString){
			shortString = len;
		}
		if( num > maxInt){
			maxInt = num;
		}
		if( num < minInt){
			minInt = num;
		}
	}

	/*Print to std out the length of the longest and shortest strings
	in the file, and the largest and smallest ints in the file. Then 
	flush the buffer to std out.
	*/
	printf("Length of shortest string: %d\n", shortString);
	fflush( stdout);
	printf("Length of longest string:  %d\n", longString);
	fflush( stdout);
	printf("Value of maximum integer:  %d\n", maxInt);
	fflush( stdout);
	printf("Value of minimum integer:  %d\n", minInt);
	fflush( stdout);

}