// S -> iCtSeS | a
// C -> b
#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

int S(), C();
char a[100], *cursor;

// ibtaea
int main(){
    printf("Grammar\nS -> iCtSeS | a\nC -> b\n");
    printf("Enter the input: ");
    scanf("%s", a);
    cursor = a;

    printf("Input\tActions\n");
    if(S() && *cursor == '\0'){
        printf("Parsed successfully\n");
        return 0;
    }
    else{
        printf("Error\n");
        return 1;
    }
}

int S(){
    // S -> iCtSeS | a
    if(*cursor == 'i'){
        printf("%s \tS -> iCtSeS\n", cursor);
        cursor++; 
        if(C()){
            if(*cursor == 't'){
                printf("%s \tS -> iCtSeS\n", cursor);
                cursor++; 
                if(S()){
                    if(*cursor == 'e'){
                        printf("%s \tS -> iCtSeS\n", cursor);
                        cursor++; 
                        if(S()){
                            
                            return SUCCESS;
                               
                        }
                    }
                }
            }
        }
    }
    
    else if(*cursor == 'a'){
        printf("%s \tS -> a\n", cursor);
        cursor++;
        return SUCCESS;
    }
    return FAILURE;
}

int C(){
    // C -> b
    if(*cursor == 'b'){
        printf("%s \tC -> b\n", cursor);
        cursor++; 
        return SUCCESS;
    }
    return FAILURE;
}
