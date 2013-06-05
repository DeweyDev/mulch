#include "std_lib_facilities.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ChemEquation.h"

// Main function

int main( void ){

	ChemEquation newone;
	int i;

	printf("%s\n","Welcome to Mulch. Enter a balanced chemical equation below");

	newone.grabInput();

	newone.parseInput();


	// Now print out the contents of the vectors

	for(i = 0; i < newone.DATA_BASE.elementNames.size(); i++){

		cout << "\n" << newone.DATA_BASE.elementNames[i] << "\n";
		cout << "\n" << newone.DATA_BASE.amountOfElement[i] << "\n";

	}


    printf("\n=========================\n");

    ChemEquation secondone("JeWs3");

    cout<< "\n" << secondone.getEquation();

	keep_window_open();
	return 0;
}
