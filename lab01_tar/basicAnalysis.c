/*
	Author: LCDR C. W. Hoffmeister
	Course: SY305 - Sys Prgm & OS Fund
	Meeting: Program Analysis Fundamentals (Part 1)

	Description: Basic program used to explore gdb.
*/

// Required Includes
// New Uses
// Previous Uses
#include <stddef.h>  // Stadnard Definition Library: NULL
#include <stdio.h>   // Stdandard I/O Library: printf(3)

// Global Constants
#define MAX_PSWD_LEN 80

// Function Prototypes
int sumInts2a( int intA, int intB, int  total );
int sumInts2b( int intA, int intB, int *total );

// main Function
int main( int argc, char *argv[] ) {
	// Declare Required Variables
	int baseYYYY = 2000, ygMod = 20 ;
	int sum = 0;
	char strPswd[ MAX_PSWD_LEN ] = "changeme";
	char goSWO = 0xE;
	int drOck = 1040, rANDx = 365;
	int cyb3r = 24589, haX0r = 2989;
	int *ptSum = &sum;
	double store = 7.11;
	// Perform Function
	printf("Stop me ...\n");

	sumInts2a( baseYYYY, ygMod, sum );
	printf("(sum): %d\n", sum);

	sumInts2a( baseYYYY, ygMod, sum );
	printf("(sum): %d\n", sum);

	sumInts2b( baseYYYY, ygMod, &sum );
	printf("(sum): %d\n", sum);
	// Return to Caller
	return 0;
}

// Store the sum of the first two int arguments in the third int argument
int sumInts2a( int intA, int intB, int total ) {
	total = intA + intB ;
	return 0;
}

// Store the sum of the first two int arguments in the third pointer to an int argument
int sumInts2b( int intA, int intB, int *total ) {
	*total = intA + intB;
	return 0;
}
