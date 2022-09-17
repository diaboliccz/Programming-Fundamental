//จงเขียนโปรแกรมเพื่อรับ String 1 ชุดแล้วแสดงผลลัพธ์เป็นสามเหลี่ยมจาก string ที่รับเข้ามา ดังตัวอย่าง (Level 3)
#include <stdio.h>
#include <string.h>

int main(){
    char str[50];
    scanf("%s", str);
    char *p=str;
    int l = strlen(str);
    while(*p!='\0'){
        for(int i=0;i<l;i++){
            printf("%c",str[i]);
        }
        l--;
        p++;
        printf("\n");
    }
    return 0;
}