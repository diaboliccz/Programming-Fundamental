//จงเขียนโปรแกรมเพื่อคำนวณหาตัวเลขฐานสองของอินพุทที่รับเข้ามา (Level 2)
#include <stdio.h>
#include <math.h>
int main(){
    int num,result[100],count=0,sum=0;
    scanf("%d",&num);
    while(num>0){
        result[count] = num%2;
        num/=2;
        count++;
    }
    for(int i=count-1;i>=0;i--){
        float k=result[i]*pow(10,i);
        sum+=k;
    }
    printf("%d\n",sum);
    return 0;
}