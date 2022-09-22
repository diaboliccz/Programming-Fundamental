#include <stdio.h>
//จงเขียนโปรแกรมเพื่อรับข้อมูลความสูงของนักเรียน 10 คน แล้วแสดงผลลัพธ์ความสูงของนักเรียน 10 คน พร้อมหาว่าความสูงเฉลี่ยของนักเรียน 10 คนเป็นเท่าไร (Level 3)
int main(){
    float height[10],average=0;
    int lenght = sizeof(height)/sizeof(float);
    for(int i=0; i<lenght; i++){
        printf("Student %d = ",i+1);
        scanf("%f",&height[i]);
    }
    printf("\n");
    for(int i = 0;i<lenght;i++){
        printf("Student %2d = %.2f\n",i+1,height[i]);
        average+=height[i]/lenght;
    }
    printf("Average height = %.2f",average);
    return 0;
}