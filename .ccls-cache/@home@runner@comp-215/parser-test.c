/*
    name: Ruth Oldja
    date: 11/16/2022
    purpose: parse mathematical expression and calculate result using EBNF grammar
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "parser.h"

// global variable that stores the current token
struct Token currentToken;

char testExpression[] = "51+5";

int main(void)
{
    // TODO: add comments
    parse();
    return 0;
}

void parse(char input[21])
{
    getToken();
    // command();
}

void getToken()
{
    // int currentChar = '0';
    int i = 0;
    int testCurrentChar = testExpression[i];

    while (isdigit(testCurrentChar))
    {
        printf("test char is digit");
        currentToken.type = NUMBER;
        currentToken.value = 10 * currentToken.value + testCurrentChar - '0';
        testCurrentChar = testExpression[i++];  
    }

    switch (testCurrentChar)
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
	int result = expr();
	
	if (currentToken.type == EOL)
    {
		printf("\nresult: %d\n", result);
	}
	else if (currentToken.type == ERROR)
    {
		printf("Command Error!!\n");	
	}
}

int expr()
{
    int result = term();

    while (currentToken.type == PLUS || currentToken.type == MINUS)
    {
        if (currentToken.type == PLUS)
        {
            match(PLUS);
            result += term();
        }
        else
        {
            match(MINUS);
            result -= term();
        }
    }

    getToken();
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
    if (currentToken.type == type)
    {
        getToken();
    }
}
