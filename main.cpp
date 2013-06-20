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

    /*for(int i = 0; i < dataBlob.size(); i++) {

        for(int xyz = 0; xyz < dataBlob[i].compoundElements.size(); xyz++) {

            double molarMass = secondone.molarMassLookup(dataBlob[i], xyz);

            cout << "Molar Mass of " << dataBlob[i].compoundElements[xyz] << ": " << molarMass << endl;

        }

    }
    */

    cout << "Molar Mass of H12 = " << secondone.molarMassLookup(dataBlob[0], 1);

    printf("\n\n====Test 4: Converting from Grams to Moles====\n\n");

    double finalMass = secondone.gramsToMolarMass(dataBlob[0], 10);

    cout << "The final molar mass of " << dataBlob[0].compoundString << " is " << finalMass << " grams per mole (g/mol)."  << endl;

    cout << "10 grams of " << dataBlob[0].compoundString << " is equivalent to " << finalMass << " moles of " << dataBlob[0].compoundString << endl;

	keep_window_open();
	return 0;
}
