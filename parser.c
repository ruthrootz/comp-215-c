/*
    name: Ruth Oldja
    date: 11/16/2022
    purpose: parse mathematical expression and calculate result using EBNF grammar
*/

#include <stdio.h>
#include <math.h>
#include "parser.h"

// global variable that stores the current token
struct Token currentToken;

int main(void)
{
    parse();
    return 0;
}

void parse(char input[21])
{
    getToken();
    command();
}

void getToken()
{
    int currentCharacter = 0;
    while ((currentCharacter = getchar()) == ' ');
    while(isdigit(currentCharacter))
    {
        currentToken.type = NUMBER;
	    //Convert character in respective digit
    	currentToken.value = 10 * currentToken.value + currentCharacter - '0';
        // read in next character
        currentCharacter = getchar();  
    }

    //  done reading all digits, out of while loop, must have found a non-digit, so push last character read in 
    // back to standard input
    ungetc(currentCharacter, stdin);

    switch (currentCharacter)
    {
        case '+':
            currentToken.type = PLUS;
            break;
        case '-':
            currentToken.type = MINUS;
            break;
        case '/':
            currentToken.type = DIVIDE;
            break;
        case '*':
            currentToken.type = MULTIPLY;
            break;
        case '%':
            currentToken.type = REMAINDER;
            break;
        case '^':
            currentToken.type = POWER;
            break;
        case '(':
            currentToken.type = LPAREN;
            break;
        case ')':
            currentToken.type = RPAREN;
            break;
        case '\0':
            currentToken.type = EOL;
            break;
        default:
            currentToken.type = ERROR;
    }
}

void command()
{
    // start parsing by calling the method for the top level of the CFG
	int result = expr();
	
	// command is done when token type is the end of line
	if (currentToken.type == EOL)
    {
		printf("\nresult: %d\n", result);
	}
	else
    {
		printf("Command Error\n");	
	}
}

int expr(void)
{
	// call term function and store result

	// while loop which checks the token type (global variable being updated by getToken) for plus 	
	// or minus
	
	// if plus, call the match function
	// if plus, result += term();  // get next term
}
