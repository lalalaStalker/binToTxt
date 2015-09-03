/*Laura Stalker
LS451494
lstalker@albany.edu
*/


#include <stdio.h>  /*Include standard i/o library*/
#include <stdlib.h>  /*To use exit function*/
#include <string.h>  /*Include the string library*/
#include "constants.h"  /*Header file with constants*/
#include "prototypes.h"  /*Header file with prototypes*/


/* A function that takes two pointers: the first to an input file,
and the second to an output file.  The input file is assumed to be
a binary file, and the output, a text file. The input file is read
and the data is stored, then the data is written to the text file.
The input file is assumed to have triplets of: length of the 
following string, a string, and an integer.  If the first of those 
three is present, we assume there will be a string and an int to 
follow.  The function does not return anything.
*/

void binaryToText( FILE* inPtr, FILE* outPtr){

	unsigned int num;  /*Integer after the string*/
	unsigned char len;  /*Length of the string*/
	char stringArray[ MAX_STRING_LENGTH];  /*Holds the string*/
	unsigned int length;  /*A variable to store char "len" in as an int*/
	length = 0;  /*Initialize to 0*/
	num = 0;  /*Initialize to 0*/
	len = 0;  /*Initialize to 0*/

	/*While there is another set of (length, string, int) to be read 
	from the file, read and store them, then write them to a formatted
	file.
	*/
	while( (fread( (void*) &len, sizeof( unsigned char), 1, inPtr)) == 1 ){
		length = len;  /*Save the char as an int*/
		
		fread( (void*) stringArray, sizeof( char), length, inPtr);
		fread( (void*) &num, sizeof( int), 1, inPtr);

		stringArray[ len] = '\0';  /*Add string termination char*/

		/*Print each string and int pair to the output file
		*/
		fprintf( outPtr, "%s\t%d\n", stringArray, num);
	}
	
}