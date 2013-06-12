//
// THIS FILE IS PART OF THE mulch SOFTWARE SOURCE CODE.
// USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS
// GOVERNED BY A GPL-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE
// IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.
//
//

//+---------------------------------------------------------------------------
//
//  DEWEY DEV, 2013.
//
//  File:       ChemEquation.cpp
//
//  Contents:   The main class of the mulch libary
//              Holds multiple methods
//              Implementation of ChemEquation.h
//
//  Classes:    ChemEquation
//
//  Functions:  parseInput()                   // parses compounds
//				elementLookup()                // dunno what this does
//				calculate()                    // same here
//
//  Author:     shrimpboyho ( shrimpboyhoftw@gmail.com )
//
//  History:    5-25-2013   shrimpboyho   Got stability workin
//
//----------------------------------------------------------------------------


#include "ChemEquation.h"
#include <ctype.h>
#include <cstring>
#include <sstream>

using namespace mulch;

// Constructors

ChemEquation::ChemEquation(string equationstringgiven)
{

    this->equationstring = equationstringgiven;

}

ChemEquation::ChemEquation(void)
{
}

// Deconstructor

ChemEquation::~ChemEquation(void)
{
}

// Get from the standard input (THIS MEMBER FUNCTION MAY SOON BE DEPRECATED)

void ChemEquation::grabInput(){

    fgets(this -> input,60,stdin);


}

// Sets the equation string if not specified in the constructor

void ChemEquation::setEquation(string givenequation){

    this -> equationstring = givenequation;

}

// Gets the equation string

string ChemEquation::getEquation(){

    return this->equationstring;

}

// A function that parses each compound and does counting

void ChemEquation::parseInput(string equationstring){

	int endOfString = 0;			    // Variable that stores the end of the string
	int i;							    // Loop counter
	int k;                              // Another loop counter
	int g;                              // Yet Another loop counter
	int z;                              // HOW MANY!!!!
	int j;                              // PLEASE STOP!
	vector <string> foundElements;      // Vector that stores the number of found elements
	vector <int> digitsFound;           // A vector that accumulates digits that will later be summed
	vector <int> amountOfFoundElements; // Vector parallel to foundElements
	string temp;                        // A temporary string
	int tempsum = 0;                    // A temporary sum of the amount of elements
	bool paren = false;                 // A boolean representing the state of parenthesis in the equation
	int digitafterparen;                // In integer representing the number after the parenthesis
    int firstcoefficientOfCompound;          // An integer representing the coefficient of the compound


    // Turn string given into an operatable character array

    for(i = 0; i < equationstring.length(); i++)
    {
        this->input[i] = equationstring[i];
    }

    // Append newline character

    input[i] = '\n';


	// Determine the end of the string

	while(input[endOfString] != '\n'){

		endOfString++;

	}

	printf("Determined the end of the string to be at the index of %d\n", endOfString);


	// Determine to see if there is a coefficient added at the begining

	for(i = 0; i < endOfString; i++){


        // See if we've hit a first number

        if(isdigit(input[i])){

            // Know that this is the coefficient number
            firstcoefficientOfCompound = input[i] - '0';
            break;
        }

        // If we've hit a letter

        if(isalpha(input[i])){

            // Know that this is the coefficient number
            firstcoefficientOfCompound = 1;
            break;
        }

	}


	// Begin scanning the string character by character

	for(i = 0; i < endOfString; i++){

		// Check to make sure its not a whitespace character

		if(isspace(input[i])){
			continue;
		}

		// Check to make sure its not a + or = character or parenthesis

		if((input[i] == '+') || (input[i] == '=')){
			continue;
		}

		if((input[i] == '(') || (input[i] == ')')){
			continue;
		}

		// Check to make sure its not a number

		if(isdigit(input[i])){
			continue;

			// We'll worry about counting digits later
		}

		// Now if its a letter

		if(isalpha(input[i])){

			// We need to check if its a single letter or a double letter element.

			/* SINGLE LETTER CHECK! */

			if(isupper(input[i]) && ( isupper(input[i+1]) || isdigit(input[i+1]) || isspace(input[i+1]) || input[i+1] == '(' || input[i+1] == ')' || input[i+1] == '+' || input[i+1] == '=')){

				temp.push_back(input[i]);

				// Inject into the vector only if it isn't already in there

				for(k = 0; k < foundElements.size(); k++){
					if(temp == foundElements[k]){
						break;
					}
				}

				if(k == foundElements.size()){
					foundElements.push_back(temp);
				}

				// Clear teh string

				temp.clear();

			}

			/* DOUBLE LETTER CHECK! */

			if(isupper(input[i]) && (!isupper(input[i+1])) && (!isspace(input[i+1])) && (!isdigit(input[i+1])) && (input[i+1] != '+')  && (input[i+1] != '=')  && (input[i+1] != ')')  && (input[i+1] != '(')){

				temp.push_back(input[i]);
				temp.push_back(input[i+1]);

				// Inject into the vector only if it isn't already in there

				for(k = 0; k < foundElements.size(); k++){
					if(temp == foundElements[k]){
						break;
					}
				}

				if(k == foundElements.size()){
					foundElements.push_back(temp);
				}

				// Clear teh string

				temp.clear();

			}

		}

	}

	// Now match the vector the public accesible vector

	this->DATA_BASE.elementNames = foundElements;

	/* BEGIN COUNTING THE AMOUNT OF ELEMENTS */

	// Loop through each of the found elements

	for(i = 0; i < foundElements.size(); i++){

		// Find instance of the element in the string of input

		for(g = 0; g < endOfString; g++){

			// See if we've hit parenthesis

			if(input[g] == '('){
				paren = true;
				continue;
			}

			if(input[g] == ')'){
				paren = false;
				continue;
			}

			// See if we're looking for a single letter element

			if(foundElements[i].size() == 1){

				if(input[g] == foundElements[i].at(0)){

					// Check to see if numbers are present after the element name and we're not in parenthesis mode

					if(isdigit(input[g + 1]) && paren == false){

						digitsFound.push_back(input[g + 1] - '0');

					}

					// If no digit is specified and parenthesis mode is off, then assume one

					if(!isdigit(input[g + 1]) && paren == false){

						digitsFound.push_back(1);

					}

					// If a digit is specified and we are in parenthesis mode do the multiplication

					if(isdigit(input[g + 1]) && paren == true){

						// Find the number after the next closing parenthesis in the input

						for(j = g + 1; j < endOfString; j++){

							if(input[j] == ')'){

								digitafterparen = input[j + 1] - '0';
								break;

							}

						}

						digitsFound.push_back((input[g + 1] - '0') * digitafterparen);

					}

					// If a digit is not specified and we are in parenthesis mode do the multiplication with one

					if(!isdigit(input[g + 1]) && paren == true){

						// Find the number after the next closing parenthesis in the input

						for(j = g + 1; j < endOfString; j++){

							if(input[j] == ')'){

								digitafterparen = input[j + 1] - '0';
								break;

							}

						}

						digitsFound.push_back(1 * digitafterparen);

					}

				}

			}

			// See if we're looking for a double letter element

			if(foundElements[i].size() == 2){

				if(input[g] == foundElements[i].at(0) && input[g + 1] == foundElements[i].at(1)){

					// Check to see if numbers are present after the element name and we're not in parenthesis mode

					if(isdigit(input[g + 2]) && paren == false){

						digitsFound.push_back(input[g + 2] - '0');

					}

					// If no digit is specified and parenthesis mode is off, then assume one

					if(!isdigit(input[g + 2]) && paren == false){

						digitsFound.push_back(1);

					}

					// If a digit is specified and we are in parenthesis mode do the multiplication

					if(isdigit(input[g + 2]) && paren == true){

						// Find the number after the next closing parenthesis in the input

						for(j = g + 2; j < endOfString; j++){

							if(input[j] == ')'){

								digitafterparen = input[j + 1] - '0';
								break;

							}

						}

						digitsFound.push_back((input[g + 2] - '0') * digitafterparen);

					}

					// If a digit is not specified and we are in parenthesis mode do the multiplication with one

					if(!isdigit(input[g + 2]) && paren == true){

						// Find the number after the next closing parenthesis in the input

						for(j = g + 2; j < endOfString; j++){

							if(input[j] == ')'){

								digitafterparen = input[j + 1] - '0';
								break;

							}

						}

						digitsFound.push_back(1 * digitafterparen);

					}

				}

			}


		}


		/* SUM UP THE CONTENTS OF digitsFound and INJECT IT*/

		for(k = 0; k < digitsFound.size(); k++){
			tempsum = tempsum + digitsFound[k];
		}

		amountOfFoundElements.push_back(tempsum * firstcoefficientOfCompound);

		// Reset sum and clear digitsFound

		tempsum = 0;
		digitsFound.clear();

	}

	// Inject into the public class

	this->DATA_BASE.amountOfElement = amountOfFoundElements;

}


/* TODO : FINISH TOKENIZER*/

/** This function is the first step of parsing the entire chemical equation
    It basically splits the equation into several compounds.

 */

void ChemEquation::tokenizer(){

	int i;
	string firstHalf;
	string secondHalf;
    string currentToken;
    string tempToken;

	// Split the equation string into two strings, one for the lefthand, one for the righthand

    istringstream streamy(this->equationstring);

    while(getline(streamy,firstHalf, '=')){

        cout << "\nHere is the first half:" << firstHalf << "\n";

        while(getline(streamy,secondHalf)){

             cout << "\nHere is the second half:" << secondHalf << "\n";

        }

    }

    /* SPLIT THE TWO HALFS INTO COMPOUNDS! */

    istringstream streamy2(firstHalf);
    istringstream streamy3(secondHalf);

    while(getline(streamy2, tempToken , '+')){

        cout << "\nHere is a token:" << tempToken << "\n";

        this->DATA_BASE.tokens.push_back(tempToken);

    }

    while(getline(streamy3, tempToken , '+')){

        cout << "\nHere is a token:" << tempToken << "\n";

        this->DATA_BASE.tokens.push_back(tempToken);

    }

    /* Now create the nice package for the calculator */

    for(i = 0; i < this->DATA_BASE.tokens.size(); i++){


        this -> package.push_back(compound());

        // Call the parser

        parseInput(this->DATA_BASE.tokens[i]);

        // Modify the package

        package[i].compoundString = this->DATA_BASE.tokens[i];
        package[i].compoundElements = this->DATA_BASE.elementNames;
        package[i].compoundElementsAmounts = this->DATA_BASE.amountOfElement;

    }


}


/** Calculator methods begin here*/

/*Element Lookup is responsible for finding the molar masses of each
individual element in a compound or series of elements that are given
to it.*/

void ChemEquation::elementLookup(mulch::compound chemicalCompound) {

	double molarMass;

	for(int i = 0; i < chemicalCompound.compoundElements.size(); i++) {

        molarMass = calculateMM(chemicalCompound.compoundElements[i], chemicalCompound.compoundElementsAmounts[i]);

        cout << "\n Molar Mass of " << chemicalCompound.compoundElements[i] << ": " << molarMass << endl;

    }
}

/*CalculateMM will calculate the molar mass of each individual
element before feeding this data back to elementLookup() to be
printed to the screen.  It contains the molar mass of every element.*/

double ChemEquation::calculateMM(string element, double quantity){

	double final;
    int i;

    i = index(element);

	vector <double> elementMasses;

	/**All element masses are below.  Do not change these numbers!!!*/

	elementMasses.push_back(1.008);
	elementMasses.push_back(4.002602);
    elementMasses.push_back(6.94);
    elementMasses.push_back(9.012182);
    elementMasses.push_back(10.81);
    elementMasses.push_back(12.011);
    elementMasses.push_back(14.007);
    elementMasses.push_back(15.999);
    elementMasses.push_back(18.9984032);
    elementMasses.push_back(20.1719);
    elementMasses.push_back(22.98976928);
    elementMasses.push_back(24.3050);
    elementMasses.push_back(26.981);
    elementMasses.push_back(28.085);
    elementMasses.push_back(30.973762);
    elementMasses.push_back(32.06);
    elementMasses.push_back(35.45);
    elementMasses.push_back(39.948);
    elementMasses.push_back(39.0983);
    elementMasses.push_back(40.078);
    elementMasses.push_back(44.955912);
    elementMasses.push_back(47.867);
    elementMasses.push_back(50.9415);
    elementMasses.push_back(51.9961);
    elementMasses.push_back(54.938045);
    elementMasses.push_back(55.845);
    elementMasses.push_back(58.933195);
    elementMasses.push_back(58.6934);
    elementMasses.push_back(63.546);
    elementMasses.push_back(65.38);
    elementMasses.push_back(69.723);
    elementMasses.push_back(72.63);
    elementMasses.push_back(74.92160);
    elementMasses.push_back(78.96);
    elementMasses.push_back(79.904);
    elementMasses.push_back(83.798);
    elementMasses.push_back(85.4678);
    elementMasses.push_back(87.62);
    elementMasses.push_back(88.90585);

	final = elementMasses[i] * quantity;


	return final;
}

/*The Indexing method is where the database of elements is contained.
This method will look up each element and return an integer that can
be used in double calculateMM() to find and calculate molar mass.*/

int ChemEquation::index(string element) {
    /*Returns an integer that can be used in a case statement for element lookup.*/
    int i;

    vector <string> elementSymbols;
    elementSymbols.push_back("H");
    elementSymbols.push_back("He");
    elementSymbols.push_back("Li");
    elementSymbols.push_back("Be");
    elementSymbols.push_back("B");
    elementSymbols.push_back("C");
    elementSymbols.push_back("N");
    elementSymbols.push_back("O");
    elementSymbols.push_back("F");
    elementSymbols.push_back("Ne");
    elementSymbols.push_back("Na");
    elementSymbols.push_back("Mg");
    elementSymbols.push_back("Al");
    elementSymbols.push_back("Si");
    elementSymbols.push_back("P");
    elementSymbols.push_back("S");
    elementSymbols.push_back("Cl");
    elementSymbols.push_back("Ar");
    elementSymbols.push_back("K");
    elementSymbols.push_back("Ca");
    elementSymbols.push_back("Sc");
    elementSymbols.push_back("Ti");
    elementSymbols.push_back("V");
    elementSymbols.push_back("Cr");
    elementSymbols.push_back("Mn");
    elementSymbols.push_back("Fe");
    elementSymbols.push_back("Co");
    elementSymbols.push_back("Ni");
    elementSymbols.push_back("Cu");
    elementSymbols.push_back("Zn");
    elementSymbols.push_back("Ga");
    elementSymbols.push_back("Ge");
    elementSymbols.push_back("As");
    elementSymbols.push_back("Se");
    elementSymbols.push_back("Br");
    elementSymbols.push_back("Kr");
    elementSymbols.push_back("Rb");
    elementSymbols.push_back("Sr");
    elementSymbols.push_back("Y");

    vector <int> atomicNumbers;

    for(int y = 0; y < 120; y++){
        atomicNumbers.push_back(y);
    }

    bool found = false;

    for(int x = 0; x < 19; x++){
        if(element == elementSymbols[x]){
            i = atomicNumbers[x];
            found = true;
            break;
        }
    }

    if(!found) {
        cerr << "Error 1: Element not found" << endl;
        i = NULL;
    }

    return i;
}


/** getCompoundData()
/
/   A nice friendly function which returns an vector packed with structs
/   (within the structs are more vectors)
/*/

vector <compound> ChemEquation::getCompoundData(){

    tokenizer();

    return this->package;


}

/** getCompoundStrings()
/
/   A nice friendly function which returns an vector packed with strings
/   Each string is a compound of the equation
/   They are in order
/*/

vector <string> ChemEquation::getCompoundStrings(){

    tokenizer();

    return this->DATA_BASE.tokens;

}

