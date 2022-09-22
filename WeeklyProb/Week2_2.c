//  จงเขียนฟังก์ชั่น factorial (Level 3)
#include <stdio.h>

int factorial(int num){
    int result = 1;
    for(int i=1;i<=num;i++){
        result*=i;
    }
    return result;
}

int main(){
    int num;
    scanf("%d",&num);
    printf("%d! = %d",num,factorial(num));
    return 0;
}