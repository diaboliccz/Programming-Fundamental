#include <stdio.h>

int main(){
    int x,y;
    scanf("%d,%d",&x,&y);
    if(x>0){
        if(y>0){
            printf("Q1");
        }
        else{
            printf("Q4");
        }
    }
    else{
        if(y>0){
            printf("Q2");
        }
        else{
            printf("Q3");
        }
    }
    return 0;
}