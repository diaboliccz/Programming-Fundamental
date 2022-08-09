#include <stdio.h>

int main(){
    float x, y_1, y_2, time;
    scanf("%f %f %f", &x, &y_1, &y_2);
    time = x/(y_1+y_2);
    printf("%.2f", time);
    return 0;
}