#include <stdio.h>

int main()
{
    int num;
    printf("Enter Number : ");
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(i==0||j==0||i==num-1||j==num-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}