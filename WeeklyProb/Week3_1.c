// จงเขียนฟังก์ชัน sqrt โดยไม่ใช้ไลบรารี math.h (Level 5)
#include<stdio.h>

double sqrt(double num){
    float temp, result;
    result = num / 2;
    temp = 0;
    while(result != temp){
        temp = result;
        result = ( num/temp + temp) / 2;
    }
    return result;
}

int main()
{
    float num;
    scanf("%f", &num);
    printf("Square root of %f is %f",num,sqrt(num));
    return 0;
}