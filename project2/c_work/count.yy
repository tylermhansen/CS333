/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
3/4/2021
*/

/* 
count.yy: Reads in a text file and tells you not only the number of rows and characters, but also how many of each vowel [a, e, i, o, u] are in the file.
*/
    int num_lines = 0, num_chars = 0,  vowels = 0;
%%
\n      ++num_lines; ++num_chars;
[aeiou] ++vowels;
.       ++num_chars;

%%

int main ( int argc, char *argv[] ) {
		

     // If there is more than one argument, pass the file in.    
    if (argc > 1)
    // What file yylex() reads input from.
    yyin = fopen( argv[1], "r" ); 
    // Function of flex, reads input until it is exhausted.
    yylex(); 
    // Increment the number of lines.
    num_lines++;
    // Print the information:
    printf("Number of lines: %i \n", num_lines);
    printf("Number of Characters: %i \n", num_chars);
    printf("Number of vowels: %i \n", vowels);
    return 0;
}