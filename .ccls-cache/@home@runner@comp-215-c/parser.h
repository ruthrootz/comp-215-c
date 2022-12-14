typedef enum
{
    PLUS,
    MINUS,
    DIVIDE,
    MULTIPLY,
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

void parse();
void getToken();
void command();
int expr();
int term();
int power();
int factor();
int factor1();
void error();
void match(TokenType tkType);
