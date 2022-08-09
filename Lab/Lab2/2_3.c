#include <stdio.h>
/*
สร้างสี่เหลี่ยมจัตุรัสกลวง 65010039
1.รับค่า num
2.ให้ i=0
3.วนเมื่อ i<num
	3.1 ให้ j=0
	3.2 วนเมื่อ j<num
		3.2.1 ถ้า (i==0 or j==0 or i==num-1 or j==num-1)
                แสดง *
                แสดง " "
		3.2.2 j=j+1
	3.3 ขึ้นบรรทัดใหม่
4.i=i+1
*/
int main()
{
    int num;
    printf("Enter Number : ");
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(i==0||j==0||i==num-1||j==num-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

