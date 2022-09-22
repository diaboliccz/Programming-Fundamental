// จงเขียนฟังก์ชั่น factorial (Level 3)
#include <stdio.h>
int factorial(int num){
    if(num==0){
        return 1;
    }
    else if(num>0){
        return num*factorial(num-1);
    }
    
}

int main(){
    int num;
    scanf("%d",&num);
    printf("Factorial of %d is %d",num,factorial(num));
    return 0;
}