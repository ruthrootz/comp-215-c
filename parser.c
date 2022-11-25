/*
    name: Ruth Oldja
    date: 11/16/2022
    purpose: parse mathematical expression and calculate result using EBNF grammar
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "parser.h"

struct Token currentToken; // stores the current token
int currentIndex = -1; // for stepping through the expression
char testExpression[] = "1-11*(2)";

int main(void)
{
    parse();
    return 0;
}

void parse()
{
    getToken(); // get the first token
    command(); // do the parsing and print the result
}

void getToken()
{
    // get the current character and reset the current token's value
    int currentChar = testExpression[++currentIndex];
    currentToken.value = 0;
    if (currentToken.type == EOL)
    {
        return;
    }

    // get the number value if the current token is a number
    while (isdigit(currentChar))
    {
        currentToken.type = NUMBER;
        currentToken.value = 10 * currentToken.value + currentChar - '0';
        if (!isdigit(testExpression[currentIndex + 1]))
        {
            printf("%d --- NUMBER\n", currentToken.value);
            currentChar = testExpression[++currentIndex];
            break; // QUESTION: turn this into a return?
        }
        currentChar = testExpression[++currentIndex];
    }

    // determine opperator
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
	int result = expr();

    // exit conditions...
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
    int result = 0;
    
    while (currentToken.type == PLUS || currentToken.type == MINUS)
    {
        if (currentToken.type == PLUS)
        {
            match(PLUS); // find the number that will be added in the line below
            result += term();
        }
        else
        {
            match(MINUS);
            result -= term();
        }
        return result;
    }
    
    result = term(); // call term() without doing anything because there's no +/-
    return result;
}

int term()
{
    int result = 0;
    
    while (currentToken.type == MULTIPLY || currentToken.type == DIVIDE)
    {
        if (currentToken.type == MULTIPLY)
        {
            match(MULTIPLY);
            result *= power();
        }
        else if (currentToken.type == REMAINDER)
        {
            match(REMAINDER);
            result %= power();
        }
        else
        {
            match(DIVIDE);
            result /= power();
        }
        return result;
    }
    
    result = power();
    return result;
}

int power()
{
    int result = 0;
    
    while (currentToken.type == POWER)
    {
        match(POWER);
        result = pow(result, factor());
        return result;
    }
    
    result = factor();
    return result;
}

int factor()
{
    int result = 0;
    
    while (currentToken.type == MINUS)
    {
        match(MINUS);
        result -= factor1();
        return result;
    }
    
    result = factor1();
    return result;
}

int factor1()
{
    int result = 0;

    while (currentToken.type == LPAREN || currentToken.type == RPAREN)
    {
        if (currentToken.type == LPAREN)
        {
            match(LPAREN);
            result = expr();
        }
        else
        {
            match(RPAREN);
            result = expr();
        }
    }

    result = currentToken.value;
    return result; // we're at the end of the grammar; return the terminal (a number)
}

void match(TokenType type)
{
    if (currentToken.type == type)
    {
        getToken();
    }
}

void error()
{
    printf("ERROR OCCURED");
}
