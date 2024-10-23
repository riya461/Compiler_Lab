%{
    #include <stdio.h>
    #include <stdlib.h>
    int i,j,flag=1;
%}

%%
[a-zA-Z0-9]* {
    for(int i=0,j= yyleng - 1; i<= j; i++, j--){
        if(yytext[i] != yytext[j]){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        printf("Palindrome %s",yytext);
    }
    else{
        printf("Not Palindrome %s",yytext);
    }
    printf("\n");

}
\n {exit(1);}
%%

int main(){
    printf("String: ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}