#include <stdio.h>
#include <string.h>

int n; // states count 

void closure(int state, int matrix[][n]){
    for(int i=0;i<n;i++){
        if(matrix[state][i] == 1){
            printf(", q%d",i);
            closure(i,matrix);
        }
    }
    return;
}

int main(){
    FILE* input = fopen("input.txt","r");
    char state1[3],in[3],state2[3];
    int s1,s2;

    printf("Number of states:   ");
    scanf("%d",&n);

    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=0;
        }
    }

    while(fscanf(input,"%s %s %s", state1,in,state2)!= EOF){
        if(strcmp(in,"e")==0){
            
            s1=state1[1]-'0';
            s2=state2[1]-'0';
            matrix[s1][s2] = 1;
        }
    }
    printf("Epsilon closure\n");
    for(int i=0;i<n;i++){
        printf("q%d: q%d",i,i);
        closure(i,matrix);
        printf("\n");
    }
}