typedef enum
{
    PLUS,
    MINUS,
    DIVIDE,
    MULT,
    REMAINDER,
    POWER,
    LPAREN,
    RPAREN,
    NUMBER,
    ERROR,
    EOL
} TokenType;

struct Token { 
    TokenType type;
    int value;
};
