#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Program Name: daysCalculatorE.c
	Author: Tina Tissington
	Last Update: Sept. 26, 2019
	Function: to find how many days are between two dates including if they're in different years.
	Compilation: gcc -ansi -o daysCalculatorE daysCalculatorE.c
	Execution: ./daysCalculatorE dd1-mm1-yyyy1 dd2-mm2-yyyy2
*/

int main ( int argc, char *argv[] ) {

	char dayStr1[3];
	char monthStr1[3];
	char yearStr1[5];

	char dayStr2[3];
	char monthStr2[3];
	char yearStr2[5];

	int dd1 = 0;
	int mm1 = 0;
	int yyyy1 = 0;

	int dd2 = 0;
	int mm2 = 0;
	int yyyy2 = 0;

	int dayTotal = 0;

	int dayOfYear1[12] = { 1, 31, 60, 91, 121, 152, 182, 213, 243, 274, 304, 335 };
	int dayOfYear2[12] = { 1, 31, 60, 91, 121, 152, 182, 213, 243, 274, 304, 335 };

	if ( argc < 3 ) {
		printf ( "Usage: ./dates dd1-mm1-yyyy1 dd2-mm2-yyyy2 \n" );
		exit ( 1 );
	} 
	else {
		dayStr1[0] = argv[1][0];
		dayStr1[1] = argv[1][1];
		dayStr1[2] = '\0';

		monthStr1[0] = argv[1][3];
		monthStr1[1] = argv[1][4];
		monthStr1[2] = '\0';

		yearStr1[0] = argv[1][6];
		yearStr1[1] = argv[1][7];
		yearStr1[2] = argv[1][8];
		yearStr1[3] = argv[1][9];
		yearStr1[4] = '\0';

		dayStr2[0] = argv[2][0];
		dayStr2[1] = argv[2][1];
		dayStr2[2] = '\0';

		monthStr2[0] = argv[2][3];
		monthStr2[1] = argv[2][4];
		monthStr2[2] = '\0';

		yearStr2[0] = argv[2][6];
		yearStr2[1] = argv[2][7];
		yearStr2[2] = argv[2][8];
		yearStr2[3] = argv[2][9];
		yearStr2[4] = '\0';
   	}
	
	dd1 = atoi ( dayStr1 );
	mm1 = atoi ( monthStr1 );
	yyyy1 = atoi ( yearStr1 );

	dd2 = atoi ( dayStr2 );
	mm2 = atoi ( monthStr2 );
	yyyy2 = atoi ( yearStr2 );
	
	if (yyyy1%4 == 0 && yyyy1%100 != 0 || yyyy1%4 == 0 && yyyy1%400 == 0) {	
		int dayOfYear1[12] = {1, 32, 61, 92, 122, 153, 183, 214, 244, 275, 305, 336};
	}

	if (yyyy2%4 == 0 && yyyy2%100 != 0 || yyyy2%4 == 0 && yyyy2%400 == 0) {
		int dayOfYear2[12] = {1, 32, 61, 92, 122, 153, 183, 214, 244, 275, 305, 336};
	}

	int day1 = dayOfYear1[mm1-1] + dd1;
	int day2 = dayOfYear2[mm2-1] + dd2;

	if ( yyyy2 == yyyy1 ) {
		dayTotal = day2 - day1;
	}
	else {
		dayTotal =  dayOfYear1[11] + 30 - day1;
		dayTotal = dayTotal + day2;
	}
	
	int x = 0;

	for (x = yyyy1 + 1; x < yyyy2; x++) {
		if (x%4 == 0 && x%100 != 0 || x%4 == 0 && x%400 == 0) {
			dayTotal = dayTotal + 366;
		}
		else {
			dayTotal = dayTotal + 365;
		}
	}

	if ( argc > 3 ) {
		if ( strcmp ( "include", argv[3] ) == 0 ) {
			dayTotal = dayTotal + 1;
		}
	}

	if ( yyyy1<yyyy2 || yyyy1==yyyy2 && mm1<mm2 || yyyy1==yyyy2 && mm1==mm2 && dd1<dd2) {
		printf ( "%d\n", dayTotal);
	}

	return ( 0 );

}
