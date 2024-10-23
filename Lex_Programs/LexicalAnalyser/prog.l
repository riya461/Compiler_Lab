%{
    int comment = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("%s This is a preprocessor directive\n",yytext);}
int | float | char | double | while | for |