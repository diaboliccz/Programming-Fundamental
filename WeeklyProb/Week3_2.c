#include <stdio.h>
double max(double num1,double num2){
    if(num1>num2){
        return num1;
    }
    else{
        return num2;
    }
}
double min(double num1,double num2){
    if(num1<num2){
        return num1;
    }
    else{
        return num2;
    }
}
double sqrt(double num){
    double x0 = num/2.0;
    double x1 = 0;
    double precision = 0.000001;
    double diff = 1;
    while(diff>precision){
        x1=0.5*(x0+num/x0);
        diff = max(x1,x0)-min(x1,x0);
        x0=x1;
    }
    return x1;
}
int main(){
    int num;
    scanf("%d", &num);
    double result = sqrt(num);
    printf("square root of %d is %.5f",num,result);
    return 0;
}