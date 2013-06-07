#pragma once
#include "std_lib_facilities.h"

class ChemEquation
{
public:

    // Representations of the entire equation

    string equationstring;

    // Representation of the token the parser is currently working with

    char input[60];

    int index(string element);

    void elementLookup(int length, int position);

    double calculateMM(string element, double quantity);


    // Public variables that will hold shit

    typedef struct
    {

        // Vectors that the parser uses (these vectors will constantly be changing)

        vector <string> elementNames;
        vector <int> amountOfElement;

        // Vectors that the tokenizer uses

        vector <string> tokens;

        // Vectors that the calculator uses

        vector <string> elementSymbols;

        vector <int> atomicNumbers;

        vector <double> elementMasses;



    } databank;

    // Instance of the database

    databank DATA_BASE;

    // Parser Member functions

    void grabInput();

    void parseInput();

    void tokenizer();


    // Calculator member functions

    void calculate(int length, int position, double quantity);

    double elementLookup(string element, double quantity);


    // Getters and setters member functions

    void setEquation(string givenequation);

    string getEquation();

    // Constructors and deconstructors

    ChemEquation(string equationstring);
    ChemEquation();
    ~ChemEquation(void);

};
