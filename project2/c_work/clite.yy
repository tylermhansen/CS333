/*
Tyler Hansen,
CS333 Spring 2021 -- Programming Languages
03/4/2021
*/
/*
clite.yy: Implements the CLITE Syntax.
*/ 
DIGIT   [0-9]
%% 
{DIGIT}*    {
            printf("Integer - %s\n", yytext );
            }
{DIGIT}+"."{DIGIT}*  {
            printf("Float - %s\n", yytext);
            }
if|else|while|for|int|float {
            printf("Keyword - %s\n", yytext);
            }
==|<|>|<=|>= {
            printf("Comparison - %s\n", yytext);
            }

=           {
            printf("Assignment\n");
            }
"+"|"-"|"*"|"/" {
            printf("Operator - %s\n", yytext);
        }           
"{"     {
            printf("Open-bracket\n");
        }
"}"     {
            printf("Close-bracket\n");
        }
"("     {
            printf("Open-paren\n");
        }

")"     {
            printf("Close-paren\n");
        }

[a-zA-Z]+ {
            printf("Identifier - %s\n", yytext);
        }
\n\\
\n
.

%%

int main ( int argc, char *argv[] ) {
		
    // If there is more than one argument, pass the file in.
    if (argc > 1)
    // What file yylex() reads input from
    yyin = fopen( argv[1], "r" ); 
    // Function of flex, reads input until it is exhausted.
    yylex(); 
    
    return 0;

}