#include <stdio.h>

int gcd_1(int a, int b);
int gcd_2(int a, int b);

int main()
{
    int a,b,c;
    printf("Enter first number : ");scanf("%d",&a);
    printf("Enter second number : ");scanf("%d",&b);
    printf("Greatest common divider = %d and %d",gcd_1(a,b),gcd_2(a,b));
    return 0;
}

int gcd_2(int a, int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b; 
        b=c;
    }
    return a;
}



int gcd_1(int a, int b){
    int min;
    if(a<b){
        min = a;
    }
    else{
        min = b;
    }
    for(int i=min;i>=1;i--){
        if((a%i==0)&&(b%i==0)){
            return i;
        }
    }
}