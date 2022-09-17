//จงเขียนโปรแกรมแปลงเวลาจากหน่วยวินาที เป็น ชั่วโมง (Level 3)
#include <stdio.h>
int main(){
    int hours,minutes,seconds;
    scanf("%d",&seconds);
    hours = seconds/3600;
    minutes = (seconds%(hours*3600))/60;
    seconds = (seconds%3600)%60;
    printf("%d:%02d:%02d",hours,minutes,seconds);
    return 0;
}