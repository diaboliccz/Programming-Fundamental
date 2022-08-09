#include <stdio.h>
/* 
แยกตัวประกอบ 65010039
1.รับค่า num,ให้ n=num
2.ให้ i=2
3.วนซ้ำถ้า i<n
    3.1 ถ้า i!= num
        3.1.1 ถ้าจริงแสดง i x
        3.1.2 ถ้าเท็จแสดง i
    3.2 i=i/num
4.เพิ่มค่า i=i+1
*/
int main(){
    int num,k,result=1;
    printf("Enter number : ");
    scanf("%d",&num);
    k=num;
    for(int i=2;i<k;i++){
        while(num%i==0){
            if(i==num){
                printf("%d ",i);
            }
            else{
                printf("%d x ",i);
            }
            num/=i;
        }
    }
    return 0;
}
