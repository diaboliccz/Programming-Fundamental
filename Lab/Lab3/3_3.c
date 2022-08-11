#include <stdio.h>

int main(){
    int num,k;
    scanf("%d",&num);
    k=num;
    for(int i=1;i<=num;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=1;i<=num;i++){
        for(int j=i;j<=num;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}