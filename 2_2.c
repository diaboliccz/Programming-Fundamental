#include <stdio.h>

int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int main()
{
    int num_1,num_2,k_1,k_2,result=1;
    printf("Enter first number : ");scanf("%d",&num_1);k_1=num_1;
    printf("Enter second number : ");scanf("%d",&num_2);k_2=num_2;
    int num = min(num_1,num_2);
    for(int i=2;i<num;i++){
        if((num_1%i==0)&&(num_2%i==0)){
            result*=i;
            num_1/=i;
            num_2/=i;
        }
    }
    printf("Greatest common divider = %d",result);
    return 0;
}