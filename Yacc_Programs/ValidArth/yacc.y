%{
    #include <stdio.h>
%}

%token NUMBER ID NL

%left '+' '-'
%left '*' '/'

%%
E : T NL {
    printf("Valid\n");
    return 0;
}
T :
    T '+' T 
    |    T '-' T 
    |    T '*' T 
    |    T '/' T 
    |    '-' NUMBER 
    |    '-' ID 
    |    '(' T ')' 
    |    NUMBER 
    |    ID 
    
%%

int main(){
    printf("Expression: ");
    yyparse();
}

int yyerror(char* s){
    printf("Invalid\n");
}