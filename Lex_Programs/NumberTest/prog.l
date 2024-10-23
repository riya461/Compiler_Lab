%{
    #include <stdlib.h>
    int positive = 0;
    int negetive = 0;
    int positive_fractions = 0;
    int negetive_fractions = 0;
%}

DIGIT [0-9]
%%
\+?{DIGIT}+ positive++;
-{DIGIT}+ negetive++;
\+?{DIGIT}*\.{DIGIT}+ positive_fractions++;
-{DIGIT}*\.{DIGIT}+ negetive_fractions++;
. ;
%%

int main(){
    yylex();
    printf("Positive numbers: %d, Negetive numbers: %d, Positive fraction numbers: %d, Negetive fraction numbers: %d\n", positive, negetive, positive_fractions, negetive_fractions);
    return 0;
}

int yywrap(){
    return 1;
}