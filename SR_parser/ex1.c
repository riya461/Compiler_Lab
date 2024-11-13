// Shift Reduce Parser
// Grammar 
// S-> (L)/a
// L->L,S/S
// (a,a)

#include <stdio.h>
#include <string.h>

int j=0,a[20],act[100];
void check();

int main(){
    printf("GRAMMAR\nS-> (L)/a\nL->L,S/S\n");
    printf("\nInput: ");
    scanf("%s",a);

    int c = strlen(a);

    printf("Stack\t\t\tInput\t\t\tActions\n");
    strcpy(act,"SHIFT->");
    for(int i=0,k=0;j<c;i++,j++,k++){
        // S -> (L)
        if(a[j] == '(' && a)
    }
    
}