#include "std_lib_facilities.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ChemEquation.h"

// Main function

int main( void ){

	int i;
	int k;

	string stuff;


    printf("\n====Test 1: Constructor and Set Input and Tokenizer======\n");

    getline(cin,stuff);

    mulch::ChemEquation secondone(stuff);

    cout << "\n" << secondone.getEquation() << "\n";


    vector <mulch::compound> dataBlob = secondone.getCompoundData();

    for(i = 0; i < dataBlob.size(); i++){


        cout << "\nDATABLOB COMPOUND STRING: " << dataBlob[i].compoundString << "\n";

        for(k = 0; k < dataBlob[i].compoundElements.size(); k++){

            cout << "\nDATABLOB COMPOUND Element: " << dataBlob[i].compoundElements[k]<< "\n";
            cout << "\nDATABLOB COMPOUND Element Amount : " << dataBlob[i].compoundElementsAmounts[k]<< "\n";

        }

    }


    printf("\n=====Test 3: Calculating Molar Mass======\n");

    secondone.elementLookup(4, 3);

	keep_window_open();
	return 0;
}
