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
int currentIndex = 0;
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
    int currentChar = testExpression[currentIndex];

    while (isdigit(currentChar))
    {
        currentToken.type = NUMBER;
        currentToken.value = 10 * currentToken.value + currentChar - '0';
        if (!isdigit(testExpression[currentIndex + 1]))
        {
            if (isdigit(currentChar))
            {        
                printf("%d --- NUMBER\n", currentToken.value);
            }
        }
        currentChar = testExpression[currentIndex++];
    }

    switch (currentChar)
    {
        case '+':
            currentToken.type = PLUS;
            printf("+ --- PLUS\n");
            break;
        case '-':
            currentToken.type = MINUS;
            printf("- --- MINUS\n");
            break;
        case '/':
            currentToken.type = DIVIDE;
            printf("/ --- DIVIDE\n");
            break;
        case '*':
            currentToken.type = MULTIPLY;
            printf("* --- MULTIPLY\n");
            break;
        case '%':
            currentToken.type = REMAINDER;
            printf("% --- REMAINDER\n");
            break;
        case '^':
            currentToken.type = POWER;
            printf("^ --- POWER\n");
            break;
        case '(':
            currentToken.type = LPAREN;
            printf("( --- LPAREN\n");
            break;
        case ')':
            currentToken.type = RPAREN;
            printf(") --- RPAREN\n");
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
	int result = expr(); // QUESTION: here or at the bottom of the method?
	
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
