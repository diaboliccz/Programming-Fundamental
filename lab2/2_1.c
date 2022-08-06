#include<stdio.h>
int main(){
    //แยกตัวประกอบ
    int num,factors_count=2,result;
    printf("Enter number : ");
    scanf("%d",&num);
    result=num;
    for(int i=1;i<result-1;i++){
        if((num-1)%i==0){
            printf("%d",i);
            do{
                printf("x");
                num/=i;
            }while()
        }
    }
    return 0;
}