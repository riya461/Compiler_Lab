%{
    #include <stdio.h>
    #include <string.h>

    char word[] = "freedom";
    int count = 0;
%}

%%
[a-zA-Z]+ {if(strcmp(yytext,word) == 0){count++;}}
. ;
%%

int main(){
    extern FILE *yyin;
    yyin = fopen("input.txt","r");
    yylex();

    printf("freedom comes %d times.\n", count);
}

int yywrap(){
    return 1;
}