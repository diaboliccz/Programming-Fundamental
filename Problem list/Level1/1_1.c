#include <stdio.h>

int main(){
    int num[2];
    printf("Num 1 = ");scanf("%d",&num[0]);
    printf("Num 2 = ");scanf("%d",&num[1]);
    printf("%d + %d = %d\n",num[0],num[1],num[0]+num[1]);
    printf("%d - %d = %d\n",num[0],num[1],num[0]-num[1]);
    printf("%d * %d = %d\n",num[0],num[1],num[0]*num[1]);
    printf("%d / %d = %d\n",num[0],num[1],num[0]/num[1]);
    return 0;
}