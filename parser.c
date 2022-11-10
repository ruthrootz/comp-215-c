/*
    name: Ruth Oldja
    date: 11/10/2022
    purpose: parse mathematical expression and calculate result
*/

#include <stdio.h>
#include <math.h>
#include "parser.h"

// global variable that stores the currently parsed token
struct Token currentToken;

int main(void) {
    // get user input
    char input[21];
    scanf("Enter a mathematical expression: %s", input);
    parse(input);
    return 0;
}

void parse(char input[21])
{
    // for each char, getToken:
        // loads up currentToken
        // prints token
    // get from 6*2-(3+4) to 
}

void getToken()
{
    
}
