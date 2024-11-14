// Grammar 
//  L -> L,S | S
//  S -> (L) | a

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];

void check() {
    strcpy(ac, "Reduce to L -> ");
    
    // L -> L, S
    for (z = 0; z <= i - 2; z++) {
        if (stk[z] == 'L' && stk[z + 1] == ',' && stk[z + 2] == 'S') {
            printf("%s L,S\n", ac);
            stk[z] = 'L';
            int k=z+1;
            while(stk[k] != '\0'){
                stk[k] = stk[k+2];
                k++;
            }
            i -= 2;
            printf("$%s\t%s$\t", stk, a);
        }
    }

    // L -> S
    for (z = 0; z <= i; z++) {
        if (stk[z] == 'S') {
            printf("%s S\n", ac);
            stk[z] = 'L';
            printf("$%s\t%s$\t", stk, a);
        }
    }

    strcpy(ac, "Reduce to S -> ");

    // S -> a
    for (z = 0; z <= i; z++) {
        if (stk[z] == 'a') {
            printf("%s a\n", ac);
            stk[z] = 'S';
            printf("$%s\t%s$\t", stk, a);
        }
    }

    // S -> (L)
    for (z = 0; z <= i - 2; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'L' && stk[z + 2] == ')') {
            printf("%s (L)\n", ac);
            stk[z] = 'S';
            int k=z+1;
            while(stk[k] != '\0'){
                stk[k] = stk[k+2];
                k++;
            }
            i -= 2; 
            printf("$%s\t%s$\t", stk, a);
        }
    }
    if (stk[0] == 'S' && stk[1] == '\0') {
        printf("Accepted\n");
        exit(0);

    } 

}

int main() {
    printf("GRAMMAR\nS -> (L) | a\nL -> L,S | S\n");
    printf("Input string: ");
    scanf("%s", a);
    c = strlen(a);

    printf("\nStack\tInput\tAction\n");
    printf("\n$\t%s$\t", a);

    strcpy(act, "SHIFT");
    for (i = 0, j = 0; j < c; i++, j++) {
        printf("%s\n", act);
        stk[i] = a[j]; 
        stk[i + 1] = '\0';
        a[j] = ' ';

        printf("$%s\t%s$\t", stk, a);
        check();
    }

    check();

    printf("\n");
    
    return 0;
}
