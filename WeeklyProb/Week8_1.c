//จงเขียนโปรแกรมเพื่อรับ String 1 ชุดแล้วแสดงผลลัพธ์เป็นสามเหลี่ยมจาก string ที่รับเข้ามา ดังตัวอย่าง (Level 3)
#include <stdio.h>

int main(){
    char str[50];
    int count = 0;
    scanf("%s", str);
    char *p=str;
    while(*p!='\0'){
        count++;
        p++;
    }
    while(count!=0){
        for(int i=0;i<count;i++){
            printf("%c",str[i]);
        }
        printf("\n");
        count--;
        p--;
    }
    return 0;
}