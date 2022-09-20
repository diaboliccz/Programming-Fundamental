#include<stdio.h> 
#include<windows.h> 
#include<time.h> 
int main() 
{ 
    int i; 
    srand( time( NULL ) ); 
    for (i=0;i<10;i++) printf("%d\n",rand()); 
    return 0; 
}