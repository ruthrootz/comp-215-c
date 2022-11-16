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
    // TODO: add comments
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
    // TODO: see if this actually works...
    while ((currentCharacter = getchar()) == ' ');
    while(isdigit(currentCharacter))
    {
        currentToken.type = NUMBER;
    	currentToken.value = 10 * currentToken.value + currentCharacter - '0';
        currentCharacter = getchar();  
    }

    ungetc(currentCharacter, stdin);

    switch (currentCharacter)
    {
        // TODO: print out tokens
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
	int result = expr();
	
	if (currentToken.type == EOL)
    {
		printf("\nresult: %d\n", result);
	}
	else
    {
		printf("Command Error\n");	
	}
}

int expr()
{
	// call term function and store result

	// while loop which checks the token type (global variable being updated by getToken) for plus or minus
	
	// if plus, call the match function
	// if plus, result += term();
    // get next term
}

int term()
{

}

int power()
{

}

int factor()
{

}

int factor1()
{

}

void error()
{

}

void match(TokenType type)
{

}
