/*Laura Stalker
LS451494


A program that...
*/

#include <stdio.h>  /*Include standard i/o library*/
#include <stdlib.h>  /*To use exit function*/
#include <string.h>  /*Include the string library*/
#include "constants.h"  /*Header file with constants*/
#include "prototypes.h"  /*Header file with prototypes*/

int main( int argc, char const *argv[]){

	FILE *infile;  /*Pointer to input file*/
	FILE *outfile;  /*Pointer to output file*/

	/*If the number of arguments given by the user is not MIN_ARGS or 
	MAX_ARGS, print an error message and exit. 
	*/
	if( (argc > MAX_ARGS) || (argc < MIN_ARGS) ){
		fprintf( stderr, 
			"Usage: fileconverter flag infile outfile(optional)\n" );
		exit(1);
	}

	/*If the number of arguments given by the user is MAX_ARGS, then 
	we will be converting a text file (formatted) into a binary file 
	(unformatted), or vice versa.
	*/
	if( argc == MAX_ARGS ){

		/*Open input file for reading. If unable to open, print an error
		message and exit.
		*/
		if( (infile = (fopen( argv[ INFILE_ARG], "r")) ) == NULL){
			fprintf(stderr, "There was an error trying to open input file
				%s for reading.\n", argv[ INFILE_ARG] );
			exit(1);
		}

		/*Open output file for writing. If unable to open, print an error
		message and exit.
		*/
		if( (outfile = ( fopen( argv[ OUTFILE_ARG], "w")) ) == NULL){
			fprintf(stderr, "There was an error trying to open output file
				%s for writing.\n", argv[ OUTFILE_ARG] );
			exit(1);
		}

		/*If the flag given is "-t", then the input file is a text file,
		so the output must be a binary file.
		*/
		if( strcmp( argv[FLAG_ARG], "-t") == 0){
			textToBinary( infile, outfile);
		}

		/*If the flag given is "-b", then the input file is a binary file,
		so the output file must be a text file.
		*/
		else if( strcmp( argv[ FLAG_ARG], "-b") == 0){
			binaryToText( infile, outfile);
		}

		/*If the flag given is not "-b" nor "-t", then print an error 
		message and exit.
		*/
		else{
			fprintf( stderr, "Invalid flag entered.\n");
			exit(1);
		}
	}

	/*If the number of arguments is MIN_ARGS, then we will be processing a
	binary file and printing information to stdout.
	*/
	else if( argc == MIN_ARGS){
		/*Check that the flag given is "-s"
		*/
		if( ( strcmp( argv[ FLAG_ARG], "-s")) == 0){

				/*Open input file for reading. If unable to open, print an error
			message and exit.
			*/
			if( (infile = (fopen( argv[ INFILE_ARG], "r")) ) == NULL){
				fprintf(stderr, "There was an error trying to open input file
					%s for reading.\n", argv[ INFILE_ARG] );
				exit(1);
			}

			/*Call the function to process the binary file and gather and 
			print info about the strings and ints in the file.*/
			binaryInfo( infile);
		}
		/*If the flag given is not "-s", print an error message and exit.
		*/
		else{
			fprintf( stderr, "Invalid flag entered.\n");
			exit(1);
		}
	}

	return 0;
}