%{
    #include <stdio.h>
%}

%token A B NL

%%
stmt: A A A A A S B NL { printf("valid string\n"); return 0;}
;
S: S A |
;
%%

int yyerror(char *msg){
    printf("Invalid string\n");
    return 0;
}

int main(){
    printf("Enter: ");
    yyparse();
}