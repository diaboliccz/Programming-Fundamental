/*
จงเขียนโปรแกรมรับตัวอักษร 1 ชุด แล้วแสดงผลลัพธ์จากหลังมาหน้า (Level 3)*/
#include <stdio.h>
#include <string.h>
int main(){
    char str[50],*p;
    p=str;
    scanf("%s",str);
    int num=strlen(str);
    while(num>=0){
        printf("%c",*(p+num));
        num--;
    }
    return 0;
}