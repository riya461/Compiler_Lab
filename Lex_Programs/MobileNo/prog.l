%{
    #include <stdlib.h>
%}

%%

[6-9][0-9]{9} {printf(" Valid\n");}
.+ {printf("Invalid  \n");}
\n {exit(1);}

%%

int main(){
    printf("Enter the mobile number: ");
    yylex();
    printf("\n");
    return 0;
}

int yywrap(){
    return 1;
}