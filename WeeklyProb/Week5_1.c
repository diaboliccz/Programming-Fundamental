#include <stdio.h>
//จงเขียนโปรแกรมเพื่อรับข้อมูลความสูงของนักเรียน 10 คน แล้วแสดงผลลัพธ์ความสูงของนักเรียน 10 คน พร้อมหาว่าความสูงเฉลี่ยของนักเรียน 10 คนเป็นเท่าไร (Level 3)
int main(){
    int height[10];
    scanf("%d %d %d %d %d %d %d %d %d %d",&height[0],&height[1],&height[2],&height[3],&height[4],&height[5],&height[6],&height[7],&height[8],&height[9]);
    printf("Student 1 = %d\nStudent 2 = %d\nStudent 3 = %d\nStudent 4 = %d\nStudent 5 = %d\nStudent 6 = %d\nStudent 7 = %d\nStudent 8 = %d\nStudent 9 = %d\nStudent 10 = %d\n",
    height[0],height[1],height[2],height[3],height[4],height[5],height[6],height[7],height[8],height[9]);

    float sum = height[0] + height[1] + height[2] + height[3] + height[4] + height[5] + height[6] + height[7] + height[8] + height[9];
    float average = sum/10;
    printf("average = %.2f\n",average);
    return 0;
}