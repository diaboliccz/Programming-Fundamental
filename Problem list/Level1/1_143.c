#include <stdio.h>

// 3600 = 1000*3 + 500*1 + 100*1

int main(){
    int num,bank1000=0,bank500=0,bank100=0;
    scanf("%d",&num);

    bank1000 = num/1000;
    num%=1000;
    
    bank500 = num/500;
    num%=500;

    bank100 = num/100;
    printf("1000 * %d\n500 * %d\n100 * %d",bank1000,bank500,bank100);
    return 0;
}