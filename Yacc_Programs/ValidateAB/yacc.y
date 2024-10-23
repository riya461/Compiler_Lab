%{
    #include <stdio.h>
%}

%token A B NL

%%
stmt: S NL { printf("valid string\n"); return 0;}
;
S: A S B |
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