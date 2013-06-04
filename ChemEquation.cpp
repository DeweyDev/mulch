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
//  File:       engine.cpp
//
//  Contents:   parses a given chemical equation
//              finds the elements present as well as their quantities
//              returns two parallel vectors .
//
//  Classes:    engine
//
//  Functions:  parseInput()
//				elementLookup()
//				calculate()
//
//  Author:     shrimpboyho ( shrimpboyhoftw@gmail.com )
//
//  History:    5-25-2013   shrimpboyho   Got stability workin
//
//----------------------------------------------------------------------------


#include "ChemEquation.h"
#include <ctype.h>
#include <cstring>

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

// Sets the equation string if not specified in the constructor

void ChemEquation::setEquation(string givenequation){

    this -> equationstring = givenequation;

}

// Gets the equation string

string ChemEquation::getEquation(){
    return this->equationstring;
}

void ChemEquation::parseInput(char input[]){

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


	// Determine the end of the string

	while(input[endOfString] != '\n'){

		endOfString++;

	}

	printf("Determined the end of the string to be at the index of %d\n", endOfString);

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

		amountOfFoundElements.push_back(tempsum);

		// Reset sum and clear digitsFound

		tempsum = 0;
		digitsFound.clear();

	}

	// Inject into the public class

	this->DATA_BASE.amountOfElement = amountOfFoundElements;

}

double ChemEquation::elementLookup(string element, double quantity){

	double final;
    int number;

	ifstream elementDatabase;



	vector <double> elementMasses;
	elementMasses[1] = 1.008;
	elementMasses[2] = 4.002602;
	elementMasses[3] = 6.94;
	elementMasses[4] = 9.012182;
	elementMasses[5] = 10.81;
	elementMasses[6] = 12.011;
	elementMasses[7] = 14.007;
	elementMasses[8] = 15.999;
	elementMasses[9] = 18.9984032;
	elementMasses[10] = 20.1797;


	return final;
}



void ChemEquation::calculate(int length, int position, double quantity) {

	double molarMass;
	for(int i = 0; i < length; i++) {

		molarMass = elementLookup(this->DATA_BASE.elementNames[position + i], quantity);
		cout << "\n Molar Mass: " << molarMass << endl;

	}

}

/* TODO : FINISH TOKENIZER*/

void ChemEquation::tokenizer(char stringInput[]){

	int endOfString = 0;

	int i;

	char tempStr[99];

	// Determine the end of the string

	while(stringInput[endOfString] != '\n'){

		endOfString++;

	}

	printf("Determined the end of the string to be at the index of %d\n", endOfString);

	// Split the inputed string into tokens (aka compounds)

	for( i = 0; i < endOfString; i++){

		if(stringInput[i] == '+'){

			strncpy(tempStr,stringInput,i);

			// Pack the token

			tempStr[i + 1] = '\n';


		}

	}


}
