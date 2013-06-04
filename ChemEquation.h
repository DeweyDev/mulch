#pragma once
#include "std_lib_facilities.h"

class ChemEquation
{
public:

    string equationstring;

    // Public variables that will hold shit

    typedef struct
    {

        // Vectors that the parser uses

        vector <string> elementNames;
        vector <int> amountOfElement;

        // Vectors that the tokenizer uses

        vector <string> tokens;



    } databank;

    // Instance of the database

    databank DATA_BASE;

    // Member functions

    void parseInput(char stringInput[]);

    void calculate(int length, int position, double quantity);

    double elementLookup(string element, double quantity);

    void tokenizer(char stringInput[]);

    void setEquation(string givenequation);

    string
    getEquation();

    // Constructors and deconstructors

    ChemEquation(string equationstring);
    ChemEquation();
    ~ChemEquation(void);

};
