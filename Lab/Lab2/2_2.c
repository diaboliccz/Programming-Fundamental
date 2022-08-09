#include <stdio.h>
/*
หา ห.ร.ม. 65010039
1.รับค่า a,b, ตั้งตัวแปร c ไว้รับเศษ
2.วนซ้ำถ้า b != 0
	2.1 c=a%b
	2.2 a=b
	2.3 b=c
3. ถ้า b=0 แล้วให้ส่งค่า a กลับมา a จะเป็น ห.ร.ม.
*/
int gcd(int a, int b);

int main()
{
    int a,b,c;
    printf("Enter first number : ");scanf("%d",&a);
    printf("Enter second number : ");scanf("%d",&b);
    printf("Greatest common divider = %d",gcd(a,b));
    return 0;
}

int gcd(int a, int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b; 
        b=c;
    }
    return a;
}



int gcd_1(int a, int b){
    int min;
    if(a<b){
        min = a;
    }
    else{
        min = b;
    }
    for(int i=min;i>=1;i--){
        if((a%i==0)&&(b%i==0)){
            return i;
        }
    }
}

