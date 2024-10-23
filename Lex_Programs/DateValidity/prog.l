%{
    #include <stdio.h>
    #include <stdlib.h>
    int valid=0, i=0, yr=0;
%}

%%
([0][1-9]|[1-2][0-9]|[3][0-1])\/(01|03|05|07|08|10|12)\/([1-2][0-9][0-9][0-9]) {valid = 1;printf("\nBatch A%s\n",yytext);}
([0][1-9]|[1-2][0-9]|(30))\/(04|06|09|11)\/([1-2][0-9][0-9][0-9]) {valid = 1; printf("\nBatch B%s\n",yytext);}
([0][1-9]|[1][0-9]|[2][0-8])\/(02)\/([1-2][0-9][0-9][0-9]) {valid = 1; printf("\nBatch C%s\n",yytext);}
29\/02\/([1-2][0-9][0-9][0-9]) {
    yr = 0,i = 6; // Starting after the '29/09/' 
    // Extract year
    while (i < yyleng) {
        yr = (10 * yr) + (yytext[i++] - '0');
    }
    //  leap year 
    if (yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0)) {
        valid = 1;
        printf("\nBatch D%s\n", yytext);
    }
}


%%
 
int main() 
{ 
    extern FILE *yyin;   
    yyin=fopen("date.txt", "r"); 
    yylex(); 
    if(valid==1) printf("It is valid date\n"); 
    else printf("It is not a valid date\n"); 
} 

int yywrap() 
{ 
 return 1; 
} 