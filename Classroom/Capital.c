#include <stdio.h>
#include <string.h>
int main(){
    char str[50];
    scanf("%s", str);
    for(int p=0;p<strlen(str);p++){
        if(str[p] >= 'A' && str[p] <= 'Z'){
            printf("%c", str[p]);
        }
    }
    return 0;
}