%{
    int vowels = 0;
    int consonants = 0;
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
\n {return 0;}
%%

int main(){
    printf("String: ");
    yylex();
    printf("Vowels, %d, Consonants, %d,\n",vowels,consonants);
    return 0;
}
int yywrap(){
    return 1;
}