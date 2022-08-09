#include <stdio.h>
#include <string.h>
int main(){
    float w,h,bmi;
    char result[60];
    printf("Height = ");scanf("%f",&w);
    printf("Width = ");scanf("%f",&h);
    if(h>2){
        h/=100;
    }
    bmi = w/(h*h);
    if(h>0&&w>0){
        if(bmi<18.5){
            strcpy(result,"Lower than standard");
        }
        else if(bmi<=24.9){
            strcpy(result,"Standard");
        }
        else if(bmi<=29.9){
            strcpy(result,"Higher than standard");
        }
        else{
            strcpy(result,"Too fat");
        }
    }
    printf("%s",result);
    return 0;
}