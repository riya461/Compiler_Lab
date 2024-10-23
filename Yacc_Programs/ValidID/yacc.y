%token DIGIT LETTER NL UND

%%
stmt: variable NL{
    printf("Valid\n");
    return 0;

}
variable: LETTER alphanumeric
;

alphanumeric: LETTER alphanumeric
| DIGIT alphanumeric
| UND alphanumeric
| LETTER
;
%%

int yyerror(char *msg){
    printf("Error Invalid\n");
    return 1;
}
int main(){
    printf("ID: ");
    yyparse();
}