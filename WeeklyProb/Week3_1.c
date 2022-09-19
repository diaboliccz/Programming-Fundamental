#include<stdio.h>

void main()
{
    int num;
    float temp, sqrt;
    scanf("%d", &num);
    sqrt = num / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( num/temp + temp) / 2;
    }
    printf("square root of %d is %f", num, sqrt);
}