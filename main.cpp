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

    for(int i = 0; i < dataBlob.size(); i++) {

        for(int xyz = 0; xyz < dataBlob[i].compoundElements.size(); xyz++) {

            cout << "\nMolar Mass of " << dataBlob[i].compoundElements[xyz] << ": " << secondone.molarMassLookup(dataBlob[i], xyz) << endl;

        }

    }

    printf("\n\n====Test 4: Converting from Grams to Moles====\n\n");

    double finalMolarMass = 0;

    for(int molesPlaceholder = 0; molesPlaceholder < dataBlob[0].compoundElements.size(); molesPlaceholder++) {

        finalMolarMass = finalMolarMass + secondone.molarMassLookup(dataBlob[0], molesPlaceholder);
    }

    double finalMoles = secondone.gramsToMoles(dataBlob[0], 10);

    cout << "The final molar mass of " << dataBlob[0].compoundString << " is " << finalMolarMass << " grams per mole (g/mol)."  << endl;

    cout << "10 grams of " << dataBlob[0].compoundString << " is equivalent to " << finalMoles << " moles of " << dataBlob[0].compoundString << endl;


    /**This loop is not finished yet

    for(int grams = 1; grams <= 10; grams++) {
        cout << "The final molar mass of ";
    }

    */

    /* THIS CODE HERE THROWS RANGE ERRORS

    //Test the first gramsToGrams with a 1:1 equation

    cout << "10 grams of " << dataBlob[0].compoundString << " in the equation above yields " << secondone.gramsToGrams(dataBlob, 10, 0, 2) << " grams of " << dataBlob[2].compoundString << "." << endl;

    //Test the second gramsToGrams with a 4:5 equation

    cout << "10 grams of " << dataBlob[0].compoundString << " in the equation above yields " << secondone.gramsToGrams(dataBlob, 10, 0, 2, 4, 5) << " grams of " << dataBlob[2].compoundString << "." << endl;

    */

    /**-----------------------------------------------------//
    //                                                      //
    //                                                      //
    //                                                      //
    //                                                      //
    //                                                      //
    //Serious tests of the calculator functions begin below.//
    //                                                      //
    //                                                      //
    //                                                      //
    //                                                      //
    //                                                      //
    //                                                      //
    //------------------------------------------------------**/

    cout << "\n\n\n=================SERIOUS TESTS=======================\n\n\n";

    string balancedEquation;

    cout << "Enter a balanced chemical equation below:" << endl;

    getline(cin, balancedEquation);

    mulch::ChemEquation chemicalEquation(balancedEquation);

    vector <mulch::compound> equationCompounds = chemicalEquation.getCompoundData();

    for(int i = 0; i < equationCompounds.size(); i++){

        cout << "The molar mass of " << equationCompounds[i].compoundString << " is " <<
        chemicalEquation.molarMassLookup(equationCompounds[i]) << " grams per mole (g/mol).\n" << endl;
    }

    cout << "Enter the amount, in grams, of " << equationCompounds[0].compoundString << ": ";

    int grams;

    cin >> grams;

    cout << "With " << grams << " grams of " << equationCompounds[0].compoundString <<
    " you can make " << secondone.gramsToGrams(equationCompounds, grams, 0, 2, 4, 5) <<
    " grams of " << equationCompounds[2].compoundString << endl;
    
    cout << "With " << grams << " grams of " << equationCompounds[0].compoundString <<
    " you can make " << secondone.gramsToGrams(equationCompounds, grams) << " grams of "
    << equationCompounds[3].compoundString << endl;



	keep_window_open();
	return 0;
}
