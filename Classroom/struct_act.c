#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    FILE* fp;
    fp = fopen("mytestfile.txt","w");
    struct player {
        char name[50];
        int level;
        int score;
    }p[5];
    for (int i = 1; i <= 5; i++) {
        scanf("%s %d %d", p[i].name, &p[i].level, &p[i].score);
    }
    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "Name : %s, Level : %d, Score : %d\n", p[i].name, p[i].level, p[i].score);
        
    }
    fclose(fp);
    return 0;
}