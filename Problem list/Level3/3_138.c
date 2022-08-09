#include <stdio.h>

int main(){
    int n0,n1,n2;
    scanf("%d",&n0);
    n1=n0/3;
    n2=(n1+n0%3)/3;
    printf("%d",n0+n1+n2);
    return 0;
}