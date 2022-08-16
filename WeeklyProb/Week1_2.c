#include <stdio.h>

int main(){
    int num;
    int result = 1;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        result*=i;
    }
    printf("Factorial of %d is %d",num,result);
    return 0;
}