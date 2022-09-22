// ให้นักศึกษารับข้อมูลเก็บใน arrayขนาด 10 ช่องแล้วแสดงค่าตัวเลขต่างๆ ใน array และแสดงตัวเลขที่เลขข้างเคียงเป็นเลขคี่ 
//ตัวอย่างการทำงานของโปรแกรม (แสดง Output หลังจากใส่ค่า Input) (Level 3)
#include <stdio.h>

int main(){
    int num[10],count=10;
    for(int i = 0;i<10;i++){
        scanf("%d",&num[i]);
    }
    int *p=num;
    while(count!=0){
        if((*(p-1)%2==1)&&(*(p+1)%2==1)){
            printf("%d ",*p);
        }
        p++;
        count--;
    }
    return 0;
}