#include <stdio.h>
//จงเขียนโปรแกรมเพื่อรับข้อมูลความสูงของนักเรียน 10 คน แล้วแสดงผลลัพธ์ความสูงของนักเรียน 10 คน พร้อมหาว่าความสูงเฉลี่ยของนักเรียน 10 คนเป็นเท่าไร (Level 3)
int main(){
    float height[10];
    float sum = 0;
    for(int i=0; i<10; i++){
        printf("Student %d = ",i+1);
        scanf("%f",&height[i]);
        sum+=height[i];
    }
    for(int i=0; i<10; i++){
        printf("student %2d = %.2f\n",i+1,height[i]);
    }
    printf("average = %.2f",sum/10);
    return 0;
}