#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
Programming Fundamental
32
ให้นักศึกษาทดลอง เขียนโปรแกรมเก็บข้อมูล
ชื่อผู้เล่น , level และ คะแนนของผู้เล่นจำนวน 5 คน
เก็บไว้ใน Binary File
Hint : ชื่อผู้เล่นไม่ควรมีเว้นวรรค
*/

/*
int main(){
    FILE *fptr;
    struct student {
        char name[20];
        int level;
        int score;
    }Player[5];
    fptr = fopen("mytestfile.txt", "w");
    for(int i=1;i<=5;i++){
        printf("Player %d : ",i);
        scanf("%s",Player[i].name);
        printf("Level : "); scanf("%d",&Player[i].level);
        printf("Score : "); scanf("%d",&Player[i].score);
        printf("\n");
        fwrite(&Player, sizeof(struct student),5,fptr);
    }
    
    fclose(fptr);
    return 0;
}*/

int main(){
    FILE *fptr;
    struct player{
        char name[20];
        int level;
        int score;
    }p[2];
    fptr = fopen("mytestfile.txt", "w");
    for(int i=1;i<=2;i++){
        printf("Player %d, Name : ",i); scanf("%s",p[i].name);
        printf("level : "); scanf("%d",&p[i].level);
        printf("score : "); scanf("%d",&p[i].score);
        fwrite(&p, sizeof(struct player),2,fptr);
        fclose(fptr);
        printf("\n");
    }
    return 0;
}