//Purpose: improve comicon_ptrs with pointers and file IO
//Name: comicon_ptrs.c
//Author: Mackenzie Zappe
//Date: 11/25/19

#include <stdio.h>
#include <string.h>

#define BADGE_SIZE 15
#define SIZE 101

void getstr(FILE *fp, int size, char array[]);
void saveBadgeNames(int size, const char original[][SIZE], char badges[][SIZE]);
void sortNames(int size, char badges[][SIZE]);

int main(int arg, char *argv[]){

FILE *input;
FILE *output;

int nameCount = 0;
char trash;
    
    if (arg != 3){
        fprintf(stderr, "Please enter two file names.\n");
    }
    if ((input = fopen (argv[1], "r")) == NULL ){
        fprintf(stderr, "Cannot open %s\n", argv[1]);
    }
     if ((output = fopen (argv[2], "w")) == NULL ){
        fprintf(stderr, "Cannot open %s\n", argv[2]);
    }
    fopen(argv[1], "r");
    fopen(argv[2], "w");
    
    fscanf(input, "%d\n", &nameCount);
    
    char inputInfo[nameCount][SIZE];
    char badges[nameCount][SIZE];
    

    int namePos = 0;
    while(namePos < nameCount){
        getstr(input, SIZE, inputInfo[namePos]);
        namePos++;
    }
    

    saveBadgeNames(nameCount, inputInfo, badges);
    fprintf(output, "Badges:\n");
    for(int i = 0; i < nameCount; i++){
        fprintf(output, "%s\n", badges[i]);

    }

    sortNames(nameCount, badges);
    fprintf(output, "\nLine Positions:\n");
    for(int i = 0; i < nameCount; i++){
        fprintf(output, "%d: %s\n", i+1, badges[i]);
    }
    
    fclose(input);
    fclose(output);

return 0;
}
void getstr(FILE *fp, int size, char array[]){
    char ch;
    int i = 0;
   
    for(; fscanf(fp, "%c", &array[i]) != EOF && i < size && array[i] != '\n'; i++);
    array[i] = '\0';
    
}
void saveBadgeNames(int size, const char original[][SIZE], char badges[][SIZE]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < BADGE_SIZE; j++){
            badges[i][j] = original[i][j];
        }
    badges[i][BADGE_SIZE + 1]  = '\0';   
    }
}
void sortNames(int size, char badges[][SIZE]){
    _Bool ordered;
    do{
        ordered = 1;
        for(int i = 0; i < size - 1; i++){
            if(strcmp(badges[i], badges[i+1]) > 0){
                char temp[SIZE];
                strcpy(temp, badges[i]);
                strcpy(badges[i], badges[i+1]);
                strcpy(badges[i+1], temp);
                ordered = 0;
            }
        }
    }while(ordered == 0);
}