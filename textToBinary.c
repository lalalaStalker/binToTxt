/*Laura Stalker
LS451494
lstalker@albany.edu
*/


#include <stdio.h>  /*Include standard i/o library*/
#include <stdlib.h>  /*To use exit function*/
#include <string.h>  /*Include the string library*/
#include "constants.h"  /*Header file with constants*/
#include "prototypes.h"  /*Header file with prototypes*/


/* A function that takes two pointers: the first to an input file, and
the second to an output file.  It is assumed that the input file is a
text file, and the output, a binary file.  Pairs of a string and an int
are read from the file, and stored.  The length of the string is 
determined, then the length, the string, and the int are written to the 
binary file.  The function does not return anything.
*/

void textToBinary( FILE* inPtr, FILE* outPtr){

	unsigned int num;  /*Integer at the end of each line*/
	unsigned char len;  /*Length of the string on each line*/
	char stringArray[ MAX_STRING_LENGTH];  /*Holds the string, with longest 
											possible length we can have*/
	num = 0;  /*Initialize to 0*/
	len = 0;  /*Initialize to 0*/

	/*While there are still lines to read in the input file,
	read and store a string and an int, then write them and 
	the length of the string to an unformatted file.
	*/
	while( (fscanf( inPtr, "%s%d", stringArray, &num) ) == FSCANF_ARGS ){
		len = strlen( stringArray);
		/*Write the length of the string, the string, and the int to the 
		binary file.
		*/
		fwrite( (void*) &len, sizeof( unsigned char), 1, outPtr);  
		fwrite( (void*) stringArray, 1, len, outPtr);
		fwrite( (void*) &num, sizeof( int), 1, outPtr);
	}

}