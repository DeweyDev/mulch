#include "std_lib_facilities.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ChemEquation.h"

// Main function

int main( void ){

	ChemEquation newone;

	int i;

	string stuff;

	printf("%s\n","Test One: grabInput()");

	newone.grabInput();

	newone.parseInput();


	// Now print out the contents of the vectors

	for(i = 0; i < newone.DATA_BASE.elementNames.size(); i++){

		cout << "\n" << newone.DATA_BASE.elementNames[i] << "\n";
		cout << "\n" << newone.DATA_BASE.amountOfElement[i] << "\n";

	}


    printf("\n====Test 2: Constructor and Set Input======\n");

    getline(cin,stuff);

    ChemEquation secondone(stuff);

    cout << "\n" << secondone.getEquation() << "\n";

    secondone.parseInput();

    // Now print out the contents of the vectors

	for(i = 0; i < secondone.DATA_BASE.elementNames.size(); i++){

		cout << "\n" << secondone.DATA_BASE.elementNames[i] << "\n";
		cout << "\n" << secondone.DATA_BASE.amountOfElement[i] << "\n";

	}

	keep_window_open();
	return 0;
}
