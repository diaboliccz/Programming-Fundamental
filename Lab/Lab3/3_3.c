#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    int side = 2*num-1;
    for(int i = 1;i<=side;i++){
        for(int j=1;j<=side;j++){
            if(i<num){
                if(j<=i||(i+j>=side+1)){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            if(i==num){
                printf("*");
            }
            if(i>num){
                if(j>=i||(i+j<=side+1)){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}