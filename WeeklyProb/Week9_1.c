// ให้นักศึกษารับข้อมูลเก็บใน arrayขนาด 10 ช่องแล้วแสดงค่าตัวเลขต่างๆ ใน array และแสดงตัวเลขที่เลขข้างเคียงเป็นเลขคี่ 
//ตัวอย่างการทำงานของโปรแกรม (แสดง Output หลังจากใส่ค่า Input) (Level 3)
#include <stdio.h>
int main(){
    int num[10];
    for(int i = 0;i<10;i++){
        scanf("%d",&num[i]);
    }
    for(int i = 1;i<9;i++){
        if((num[i-1]%2==1)&&(num[i+1]%2==1)){
            printf("%d ",num[i]);
        }
    }
    return 0;
}