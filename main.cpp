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

    // Test Constructor

    mulch::ChemEquation secondone(stuff);

    // Test getEquation()

    cout << "\n" << secondone.getEquation() << "\n";

    // Test getCompoundData()

    vector <mulch::compound> dataBlob = secondone.getCompoundData();

    for(i = 0; i < dataBlob.size(); i++){


        cout << "\nDATABLOB COMPOUND STRING: " << dataBlob[i].compoundString << "\n";

        for(k = 0; k < dataBlob[i].compoundElements.size(); k++){

            cout << "\nDATABLOB COMPOUND Element: " << dataBlob[i].compoundElements[k]<< "\n";
            cout << "\nDATABLOB COMPOUND Element Amount : " << dataBlob[i].compoundElementsAmounts[k]<< "\n";

        }

    }

    // Test the getCompoundStrings()

    cout << "\nSecond Compound is: " << secondone.getCompoundStrings()[1];


    // Test calculator functions


    printf("\n\n=====Test 3: Calculating Molar Mass======\n\n");

    /*

    cout << "Identify the compound you would like to check the molar mass of: ";

    int compoundID;

    cin >> compoundID;

    */

    for(int i = 0; i < dataBlob.size(); i++) {

        secondone.molarMassLookup(dataBlob[i]);

    }

    printf("\n\n====Test 4: Converting from Grams to Moles====\n\n");

    /*

    cout << "Please enter the amount in grams of the first compound: ";

    int compoundGrams;

    cin >> compoundGrams;

    */

    secondone.gramsToMolarMass(dataBlob[0], 10);

	keep_window_open();
	return 0;
}
