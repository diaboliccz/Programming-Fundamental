#include <stdio.h>

int main(){
    int n0,n1,sum;
    scanf("%d",&n0);
    sum = n0;
    while(n0>=3){
        n1=n0/3;
        sum+=n1;
        n0 = n1+n0%3;
    }
    printf("%d\n",sum);
    return 0;
}