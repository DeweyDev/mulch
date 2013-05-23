#include "engine.h"
#include <ctype.h>


engine::engine(void)
{
}


engine::~engine(void)
{
}

void engine::parseInput(string input){

	int i;
	string temp;
	vector <string> foundElements;

	//scan through teh entire string

	for(i = 0; i < input.size(); i++){

		// scan each character if it is a letter

		if(isalpha(input[i]) && isupper(input[i])){

			// is it a one letter element or a two letter element?

			if(isalpha(input[i + 1]) && islower(input[i + 1])){

				// We have a two letter element and shove it in
				temp.append(1,input[i]);
				temp.append(1,input[i + 1]);

				cout << "\nShoved in: " << temp << "\n";

				foundElements.push_back(temp);

				i++;
				temp.clear();

			}else if((isalpha(input[i + 1]) && isupper(input[i + 1])) || isdigit(input[i + 1]) || isspace(input[i + 1])){

				// we have a one letter element and shove it in
				temp.append(1,input[i]);

				cout << "\nShoved in: " << temp << "\n";
				foundElements.push_back(temp);

				temp.clear();

			}




		}


	}

}