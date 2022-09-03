#include <stdio.h>

int isPrime(int num){
    int count = 0;
    for(int i = 1;i<=num;i++){
        if(num%i==0){
            count++;
        }
    }
    if(count>2 && num!=1){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int num;scanf("%d", &num);
    if(isPrime(num) == 1) printf("Prime Number");
    else printf("Not Prime Number");return 0;
}