%{
    #include <stdio.h>
%}

%%
\n {printf("\n"); return 0;}
"abc" {printf("ABC");}
. printf("%s", yytext);
%%

int main(){
    printf("String: ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}