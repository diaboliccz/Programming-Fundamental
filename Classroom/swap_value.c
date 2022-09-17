
#include <stdio.h>
void swap(int *x, int *y)
{
    int c = *x;
    *x = *y;
    *y = c;
}
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    swap(&x, &y);
    printf("%d %d", x, y);
    return 0;
}