/*
 จงเขียนโปรแกรมรับตัวอักษร 1 ชุด แล้วแสดงผลลัพธ์จากหลังมาหน้า (Level 3)*/
#include <stdio.h>
#include <string.h>
int main(){
    char str[50];
    scanf("%s",&str);
    for(int i=0;i<strlen(str);i++){
        printf("%c",str[strlen(str)-i-1]);
    }
    printf("\n");
    return 0;
}