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
//  Contents:   implementation for rpattern methods, definitions for all the
//              subexpression types used to perform the matching, the
//              charset class definition .
//
//  Classes:    engine
//
//  Functions:  parseInput()
//
//  Author:     shrimpboyho ( shrimpboyhoftw@gmail.com )
//
//  History:    5-25-2013   shrimpboyho   Got stability workin
//
//----------------------------------------------------------------------------


#include "engine.h"
#include <ctype.h>

// Constructor

engine::engine(void)
{
}

// Deconstructor

engine::~engine(void)
{
}

void engine::parseInput(char input[]){

	int endOfString = 0;			// Variable that stores the end of the string
	int i;							// Loop counter
	int k;                          // Another loop counter
	vector <string> foundElements;  // Vector that stores the number of found elements
	string temp;                    // A temporary string


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

		// Check to make sure its not a number

		if(isdigit(input[i])){
			continue;

			// We'll worry about counting digits later
		}

		// Now if its a letter

		if(isalpha(input[i])){

			// We need to check if its a single letter or a double letter element.

			/* SINGLE LETTER CHECK! */

			if(isupper(input[i]) && ( isupper(input[i+1]) || isdigit(input[i+1]) || isspace(input[i+1]))){

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

			if(isupper(input[i]) && (!isupper(input[i+1])) && (!isspace(input[i+1])) && (!isdigit(input[i+1])) ){

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

	// Now print out the contents of the vectors

	for(i = 0; i < foundElements.size(); i++){

		cout << "\n" << foundElements[i] << "\n";

	}

}