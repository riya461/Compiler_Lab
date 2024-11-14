#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

int S(), L(), L_prime();
char a[100], *cursor;

void remove_left_recursion(char *non_terminal, char *prod1, char *prod2) {
    printf("%s -> %s %s'\n", non_terminal, prod2, non_terminal);
    printf("%s' -> %s %s' | ε\n", non_terminal, prod1, non_terminal);
}

int main() {
    printf("Grammar\nS -> (L) | a\nL -> L,S | S\n");

    printf("\nRemoving left recursion:\n");
    remove_left_recursion("L", ", S", "S");

    printf("Enter the input: ");
    scanf("%s", a);
    cursor = a;

    printf("Input\tActions\n");
    if (S() && *cursor == '\0') {
        printf("Parsed successfully\n");
        return 0;
    } else {
        printf("Error\n");
        return 1;
    }
}

int S() {
    // S -> (L) | a
    if (*cursor == '(') {
        printf("%s \tS -> (L)\n", cursor);
        cursor++; 
        if (L()) {
            if (*cursor == ')') {
                printf("%s \tS -> (L)\n", cursor);
                cursor++; 
                return SUCCESS;
            }
        }
    } else if (*cursor == 'a') {
        printf("%s \tS -> a\n", cursor);
        cursor++; 
        return SUCCESS;
    }
    return FAILURE;
}

int L() {
    // L -> S L'
    if (S()) {
        if (L_prime()) {
            return SUCCESS;
        }
    }
    return FAILURE;
}

int L_prime() {
    // L' -> , S L' | ε
    if (*cursor == ',') {
        printf("%s \tL' -> , S L'\n", cursor);
        cursor++; 
        if (S()) {
            if (L_prime()) {
                return SUCCESS;
            }
        }
        return FAILURE;
    }
    // ε transition for L'
    printf("%s \tL' -> ε\n", cursor);
    return SUCCESS;
}
