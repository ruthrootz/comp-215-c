# design for EBNF parser

### Ruth Oldja
### assignment 7.2
### 11/16/2022

## global variables
- `currentToken`, holds a `Token` and gets updated with `getToken()`
- `currentIndex` is the index of the character being parsed within the `testExpression`

## parse()
This will get the first token and then proceed to run `command()` beginning the parsing.

## getToken()
This will increment the current index and either get the next number or opperator.

## command()
This is the function representing the top layer of the context-free grammar. It will call `expr()`, save the result, then check if we're at the end of the expression and print the result if we are.

## the logic...

For each rule in the CFG, there will be one function. And each of those functions will be called from a "parent" function, based on what the current token is. For example, if the token is a `MINUS`, then the `term()` function is called and the result of it will be subtracted from `result`.

If the token is a `NUMBER`, it will skip all the conditional statements in all the rule methods until it gets to the bottom of `factor1()`, at which point it will simply return the value of the current token. The number is a "terminal".
