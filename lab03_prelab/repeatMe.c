#include <stdio.h>

/*
Write a short C program which will print a single character several times.  It should prompt the user for the character, verify it is in the printable range, then prompt the user for the number of repetitions, and finally display the character that number of times on screen.
*/
int repeat_char( char c, int r);

int main( ) {
	char character;	
	int repetitions, total;

	// Prompt the user for the character
	printf("Enter a character you would like to have repeated: ");
	scanf( "%c", &character);

	// Verify it is within the printable range in ASCII
	// Character should be between 32 - 127
	if ( character > 32  && character < 127) {

			// IF it's within that range, request number from the user
			puts( "Enter the number of times to repeat: " );
			scanf( "%d", &repetitions);

			// Call a function to repeat printing that character the number of times given
			total = repeat_char( character, repetitions);

	}
	// print a message to the user when complete
	puts( "All done.");

	return 0;
}

int repeat_char( char c, int r) {
	int t; // will hold the total
	
	for ( t=0; t < r; t++ ) {
		printf("%c ", c);
	}
	
	return t;
}
