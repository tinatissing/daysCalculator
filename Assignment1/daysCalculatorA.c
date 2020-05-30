#include <stdio.h>
#include <stdlib.h>

/*
	Program Name: daysCalculatorA.c
	Author: Tina Tissington
	Last Update: Sept. 23, 2019
	Function: to find how many days are between two dates
	Compilation: gcc -ansi -o daysCalculatorA daysCalculatorA.c
	Execution: ./daysCalculatorA dd1 mm1 yyyy1 dd2 mm2 yyyy2
*/

int main ( int argc, char *argv[] ) {

	char *monthName[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	int dd1 = 0;
	int mm1 = 0;
	int yyyy1 = 0;

	int dd2 = 0;
	int mm2 = 0;
	int yyyy2 = 0;

	int dayOfYear1[12] = { 1, 31, 60, 91, 121, 152, 182, 213, 243, 274, 304, 335 };
	int dayOfYear2[12] = { 1, 31, 60, 91, 121, 152, 182, 213, 243, 274, 304, 335 };

	if ( argc < 7 ) {
		printf ( "Usage: ./dates dd1 mm1 yyyy1 dd2 mm2 yyyy2 \n" );
		exit ( 1 );
	} 
	else {
		dd1 = atoi ( argv[1] );
		mm1 = atoi ( argv[2] );
		yyyy1 = atoi ( argv[3] );
		dd2 = atoi ( argv[4] );
		mm2 = atoi ( argv[5] );
		yyyy2 = atoi (argv[6] );
   	}
	
	if (yyyy1%4 == 0 && yyyy1%100 != 0 || yyyy1%4 == 0 && yyyy1%400 == 0) {
		int dayOfYear1[12] = {1, 32, 61, 92, 122, 153, 183, 214, 244, 275, 305, 336};
	}

	if (yyyy2%4 == 0 && yyyy2%100 != 0 || yyyy2%4 == 0 && yyyy2%400 == 0) {
		int dayOfYear2[12] = {1, 32, 61, 92, 122, 153, 183, 214, 244, 275, 305, 336};
	}

	int day1 = dayOfYear1[mm1-1] + dd1;
	int day2 = dayOfYear2[mm2-1] + dd2;

	int answer = day2 - day1;

	printf ( "%d\n", answer );

	return ( 0 );

}
