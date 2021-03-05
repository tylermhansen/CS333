/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
3/4/2021
*/

/* 
encode.yy: Performs a simple encoding on lowercase letters a-z.
*/
%% 
[a-z] {
    char matched = yytext[0]; 
    char shifted =  ((matched + 13 - 97) % 26) + 97;
    printf("%c\n", shifted);}
\n
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