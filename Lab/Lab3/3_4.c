#include <stdio.h>

int main(){
    int x,result;
    scanf("%d",&x);
    for(int a = 2;a<=x;a++){
        if(x%a==0){
            if(a==x){
                printf("Prime");
                break;
            }
            else{
                printf("Not Prime");
                break;
            }
        }
    }
    return 0;
}