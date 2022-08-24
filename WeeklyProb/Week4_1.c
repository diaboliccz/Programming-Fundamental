#include <stdio.h>
int main(){
    int num,result[100],count=0;
    scanf("%d",&num);
    while(num>0){
        result[count] = num%2;
        num/=2;
        count++;
    }
    for(int i=count-1;i>=0;i--){
        printf("%d",result[i]);
    }
    return 0;
}