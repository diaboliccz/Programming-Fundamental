#include <stdio.h>

double sqrt(double num){
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
    printf("%.9f",sqrt(144));
    return 0;
}