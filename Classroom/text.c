#include<stdio.h>
int ga = 10, gb = 20;
int f1(int a, int b) { a = a * 2; b = b * 3; ga = ga + 1; return a + b; }
int f2(int* a, int* b) { *a = *a + 3; *b = *b + 1; gb = gb + 2; return *a + *b; }
int f3(int a, int* b) { a = a + 5; *b = *b + 1; ga += gb; return a + *b; }
int main()
{
    FILE* fp;
    fp = fopen("mytestfile.txt","a");
    int la = 1, lb = 2;
    fprintf(fp,"A: %d %d %d %d\n", ga, gb, la,lb); // 10 20 1 2
    //lb = f1(ga, gb);
    gb = f1(la, lb);
    fprintf(fp,"B: %d %d %d %d\n", ga, gb, la, lb); // 11 8 1 2 
    ga = f2(&la, &lb);
    fprintf(fp,"C: %d %d %d %d\n", ga, gb, la, lb); // 7 10 4 3
    lb = f3(ga, &gb);
    fprintf(fp,"D: %d %d %d %d\n", ga, gb, la, lb); // 18 11 4 23
    fclose(fp);
    return 0;
}