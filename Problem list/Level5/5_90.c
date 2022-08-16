#include <stdio.h>
double num;
double sqrt(){
    double x_0 = num/2;
    double x_1;
    double precision = .00000001;
    double difference = x_1 - x_0;
    while (difference >= precision){
        x_1 = .5*(x_0 + num/x_0);
    }
    return x_1;
}
int main(){
    scanf("%f", &num);
    printf("%.4f", sqrt(num));
    return 0;
}