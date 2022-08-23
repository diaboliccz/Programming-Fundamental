#include <stdio.h>
#include <math.h>
int main(){
    float num;
    scanf("%f",&num);
    float result=sqrt(num);
    printf("Square root of %.0f is %.5f",num,result);
    return 0;
}