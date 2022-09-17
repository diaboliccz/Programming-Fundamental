//จงเขียนโปรแกรมแปลงเวลาจากหน่วยวินาที เป็น ชั่วโมง (Level 3)
#include <stdio.h>

int main(){
    int num;
    int hours,min,sec;
    printf("Input Second : ");scanf("%d",&num);
    hours = num/3600;
    num=num-hours*3600;
    min = num/60;
    num=num-min*60;
    sec = num;
    if((hours || min || sec) == 0){
        printf("");
    }
    printf("%d:%02d:%02d",hours,min,sec);
    return 0;
}