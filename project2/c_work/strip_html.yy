/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
3/4/2021
*/

/* 
strip_html.yy: Strips an HTML file of all tags and comments.
*/
    int input_tag = 0, input_p = 0, input_comment = 0;
SPACE   [\n\t ]
%%
\<p     input_tag = 1; input_p = 1;
\<!--   input_comment = 1;
\<      input_tag = 1;
\>      input_tag = 0; if (input_p) { printf("\n\n"); } input_p = 0; input_comment = 0;
{SPACE} 
.       if (!input_comment && !input_tag) { printf("%c",yytext[0]); }
%%
int main(int argc, char *argv[]) {
    // If there is more than one argument, pass the file in.
    if (argc > 1)
    // What file yylex() reads input from
    yyin = fopen( argv[1], "r" ); 
    // Function of flex, reads input until it is exhausted.
    yylex(); 
    printf("\n");
    return 0;
}