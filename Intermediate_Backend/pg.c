#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char inp[100], reg = 'Z';
char inter_code[200] = "", target_code[200] = "";
char instr[20];
   
void code_op(char opr, char *typ) {
    
    int i = 0, j = 0;
    
    while (inp[i] != '\0') {
        if (inp[i] == opr) {
            
            sprintf(instr,"%c\t%c\t%c\t%c\n", opr, reg, inp[i-1], inp[i+1]);
            strcat(inter_code, instr);

            if (strcmp(typ, "MOV") != 0) {
                
                sprintf(instr, "MOV %c,%c\n", inp[i-1], reg);
                strcat(target_code, instr);
                sprintf(instr, "%s %c,%c\n", typ, inp[i+1], reg);
                strcat(target_code, instr);
            } else {
                char target_instr[20];
                sprintf(instr, "MOV %c,%c\n", inp[i-1], inp[i+1]);
                strcat(target_code, instr);
            }

            
            inp[i-1] = reg;
            reg--;
            j = i;
            while (inp[j] != '\0') {
                inp[j] = inp[j+2];
                j++;
            }
        }
        i++;
    }
}

void int_code() {
    sprintf(instr,"Opr\tReg\tOp1\tOp2\n");
    strcat(inter_code,instr);
    code_op('/', "DIV");
    code_op('*', "MUL");
    code_op('+', "ADD");
    code_op('-', "SUB");
    code_op('=', "MOV");
}

int main() {
    printf("Enter the expression: ");
    scanf("%s", inp);

    int_code();

    printf("\nIntermediate Code:\n%s", inter_code);
    printf("\nTarget Code:\n%s", target_code);

    return 0;
}
