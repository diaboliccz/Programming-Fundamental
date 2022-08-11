#include <stdio.h>

int main(){
    int num,sum;
    scanf("%d",&num);
    for(int j=1;j<=num;j++){
        sum=0;
        for(int i=1;i<j;i++){
            if(j%i==0){
            sum+=i;
            }
        }
        if(sum==j){
            printf("%d\n",j);
        }
    }
    
    return 0;
}