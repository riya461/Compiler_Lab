%{
    int comment = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.* {printf("%s This is a preprocessor directive\n",yytext);}

int | 
float | 
char | 
double | 
while | 
for | 
struct | 
typedef | 
do | 
if | 
break | 
continue | 
void | 
switch | 
return | 
else | 
goto { printf("%s is a keyword\n", yytext);}

"/*" {comment=1; printf("%s is a comment\n", yytext);}

{identifier}\( {if(!comment) printf("Function \n %s \n", yytext);}

\{ {if(!comment) printf("\n BLOCK Begins");}
\} {if(!comment) printf("BLOCK ENDS");}

{identifier} {if(!comment) printf("%s is an identifier\n", yytext);}

\".*\" {if(!comment) printf("%s is an string\n", yytext);}

[0-9]+ {if(!comment) printf("%s is an number\n", yytext);}

\)(\:)? {if(!comment) printf("\n\t");ECHO;printf("\n");}

\( ECHO;

\+ | 
\- | 
\/ | 
\*  {if(!comment ) printf("%s is an ARITHEMETIC Operator\n",yytext);}


\<= | 
\>= | 
\< | 
\> | 
==  { if(!comment ) printf("%s is an RELATIONAL Operator\n",yytext);}


= {if(!comment ) printf("%s is an ASSIGNMENT Operator\n",yytext);}
. {ECHO; printf("\n");}
%%

int main(){
    extern FILE *yyin;
    yyin = fopen("var.c", "r");
    yylex();
    printf("\n");
    return 0;
}

int yywrap()
{
    return 1;
}