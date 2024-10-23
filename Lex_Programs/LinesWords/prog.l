%{
    int lines = 0;
    int words = 0;

%}

%%
[\n] {lines++; }
[^\t\n ]+ {words++; }

%%

int main(){
    extern FILE *yyin;
    yyin = fopen("input.txt","r");
    yylex();
    printf("Lines: %d\n",lines);
    printf("Word: %d\n",words);
}

int yywrap(){
    return 1;
}