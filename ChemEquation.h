#pragma once
#include "std_lib_facilities.h"

namespace mulch {

    struct compound {

        string compoundString;
        vector <string> compoundElements;
        vector <int> compoundElementsAmounts;

    };

    class ChemEquation {

        public:

        // Representations of the entire equation

        string equationstring;

        // Representation of the token the parser is currently working with

        char input[60];


        /** PACKAGE VARIABLES
        //
        //  These are some important structs/stuff that you don't want to mess with
        //
        */

        vector <compound> package;


        /** INTERFACE STRUCTURE
        //
        //  A nice structure which serves as a common database for member functions
        //
        */

        typedef struct {

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

        void parseInput(string equationstring);

        void tokenizer();

        // Calculator member functions

        int index(string element);

        void molarMassLookup(mulch::compound chemicalCompound);

        void gramsToMolarMass(mulch::compound chemicalCompound, double grams);

        double calculateMM(string element, double quantity);


        /** GENERAL PUBLIC FUNCTIONS
        //
        //  These are the functions that are meant to be used by the general public
        //
        //
        */

        // Getters and setters member functions

        void setEquation(string givenequation);

        string getEquation();

        vector <compound> getCompoundData();

        vector <string> getCompoundStrings();

        // Constructors and deconstructors

        ChemEquation(string equationstring);

        ChemEquation();

        ~ChemEquation(void);


    };

}
