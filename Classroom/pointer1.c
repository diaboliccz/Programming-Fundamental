#include <stdio.h>
int main(){
    char *p,str[50];
    p=str;
    scanf("%s",str);
    while(*p!='\0'){
        if((*p >='a'&&*p<='z')||(*p >='A'&&*p<='Z')){
            if((*p >='a'&&*p<='z')){
                printf("%c",*p-32);
                p++;
            }
            else if((*p >='A'&&*p<='Z')){
                printf("%c",*p+32);
                p++;
            }
        }
        else{
            p++;
        }
    }
    return 0;
}