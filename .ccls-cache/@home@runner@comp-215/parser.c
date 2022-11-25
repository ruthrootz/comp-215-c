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
int result = 0; // stores result of expression

char testExpression[] = "511+5-((6^2))";

int main(void)
{
    parse();
    return 0;
}

void parse(char input[21])
{
    getToken(); // get the first token
    command(); // do the parsing and print the result
}

void getToken()
{
    // get the current character and reset the current token's value
    int currentChar = testExpression[++currentIndex];
    currentToken.value = 0;

    // get the number value if the current token is a number
    while (isdigit(currentChar))
    {
        currentToken.type = NUMBER;
        currentToken.value = 10 * currentToken.value + currentChar - '0';
        if (!isdigit(testExpression[currentIndex + 1]))
        {
            printf("%d --- NUMBER\n", currentToken.value);
            currentChar = testExpression[++currentIndex];
            break;
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
	result = expr();

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
            result += term();
            match(PLUS);
        }
        else
        {
            result -= term();
            match(MINUS);
        }
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
            result *= power();
            match(MULTIPLY);
        }
        else if (currentToken.type == REMAINDER)
        {
            result %= power();
            match(REMAINDER);
        }
        else
        {
            result /= power();
            match(DIVIDE);
        }
    }
    
    result = power();
    return result;
}

int power()
{
    int result = 0;
    
    while (currentToken.type == POWER)
    {
        result = pow(result, factor()); // TODO
        match(POWER);
    }
    
    result = factor();
    return result;
}

int factor()
{
    int result = 0;
    
    while (currentToken.type == MINUS) // TODO
    {
        result -= factor1();
        match(MINUS);
    }
    
    result = factor1();
    return result;
}

int factor1()
{
    int result = 0;
    
    while (currentToken.type == LPAREN)
    {
        result = expr();
        match(LPAREN); // BUG
    }
    
    // QUESTION: keep going if we're not at the end yet
    match(currentToken.type);
    return currentToken.value; // ???
}

void error()
{
    printf("ERROR OCCURED");
}

void match(TokenType type)
{
    if (currentToken.type == type)
    {
        getToken();
    }
}
