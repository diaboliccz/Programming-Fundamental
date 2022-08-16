#include <stdio.h>
int main(){
    int num,result,sum=0;
    int result_1,sum_1;
    scanf("%d",&num);
    while(num>0){
        result=num%10;
        num/=10;
        sum+=result;
    }
    while(sum>0){
        result_1=sum%10;
        sum/=10;
        sum_1+=result_1;
    }
    printf("%d\n",sum_1);
    return 0;
}