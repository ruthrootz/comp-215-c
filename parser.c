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
    // for each char
        // skip if it's whitespace
            // int currentCharacter = 0;
            // while ((currentCharacter=getchar()) == ' ');
        // get all digits if it's a number
            // while(isdigit(currentCharacter)){
	           //  token.value=10*token.value+currentCharacter - '0';
            //     currentCharacter=getchar();  
            // }
        // call getToken
    // 

    // example expression: 6 * 2 - ( 3 + 4 )
}

void getToken()
{
    // create new Token
    // assign it to global variable
}
