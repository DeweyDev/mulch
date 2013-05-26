#include "std_lib_facilities.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "engine.h"

// Main function

int main( void ){
	
	engine newone;
	char input[60];

	printf("%s\n","Welcome to Mulch. Enter a balanced chemical equation below");
	
	fgets(input,60,stdin);

	newone.parseInput(input);

	keep_window_open();
	return 0;
}