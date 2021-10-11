//Purpose: making a memory matching game for our final project
//Name: memory.c
//Authors: Mackenzie Zappe and Logan Johnson
//Date: 11/30/19

#include <stdio.h> 
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <stdlib.h>

#define MAX_NAMES 10
#define MAX_ROWS 100
#define MAX_COLS 100

void displayMenu();
void emptyGrid(int dimensions);
void printGrid(int dimensions, char grid[MAX_ROWS][MAX_COLS]);
void fillGrid(int dimensions, char grid[MAX_ROWS][MAX_COLS]);
void setUp(int dimensions, char grid[MAX_ROWS][MAX_COLS]);
char * coordinates(int dimensions, char grid[MAX_ROWS][MAX_COLS], int run);
void printGridPos(int dimensions, char grid[MAX_ROWS][MAX_COLS], char * pos);
_Bool compareCoords(char * ptr1, char * ptr2);
int playGame (int dimensions, char grid[MAX_ROWS][MAX_COLS]);
void printMatchingPair(int dimensions, char grid[MAX_ROWS][MAX_COLS], char * pair);
void printMatches(int dimensions, char grid[MAX_ROWS][MAX_COLS], char * set1, char * set2);
void sort(int scores[MAX_NAMES], char names[MAX_NAMES][MAX_COLS]);
void saveScores1(int score);
_Bool fileEmpty(FILE * fp);
void saveScores(FILE *fp, int scores);
int readScores(int score[], char nameArr[][MAX_COLS]);
void writeScores(int numberofscores, int score[], char nameArr[][MAX_COLS]);

int main(){

int userInput, difficulty, finalScore, score[MAX_NAMES], quantNames;
char playingGrid[MAX_ROWS][MAX_COLS], nameArr[MAX_NAMES][MAX_COLS];


    do{
        displayMenu();
        scanf("%d", &userInput);
        if(userInput > 2 || userInput < 0){
            printf("Invalid Menu Input. Try again.\n");
        }
            switch(userInput){
                case 1: 
                    do{
                    printf("Enter a difficulty (1, 2, or 3):");
                    scanf("%d", &difficulty);
                        if(difficulty > 3 || difficulty < 1){
                            printf("Invalid Difficulty Input. Try again.\n");
                        }
                    }while(!(difficulty < 4 && difficulty > 0));
                    switch(difficulty){
                        case 1:
                            finalScore = playGame(difficulty*2, playingGrid);
                            saveScores1(finalScore);
                            /*
                            quantNames = readScores(score, nameArr);
                            writeScores(quantNames, score, nameArr);
                            FILE * fp;
                            fp = fopen("scores.txt", "w");
                            saveScores(fp,finalScore);
                            fclose(fp);
                            */
                           break;
                        case 2:
                            finalScore = playGame(difficulty*2, playingGrid);
                            //saveScores1(finalScore);
                            break;
                        case 3:
                            finalScore = playGame(difficulty*2, playingGrid);
                            //saveScores1(finalScore);
                        break;
                    }
                break;
                case 2:
                return 0;
                break; 

            }

    } while(userInput != 0);

return 0;
}

void displayMenu(){

    printf("***Memory***\n");
    printf("1 - Play Game\n");
    printf("2 - View Scores\n");
    printf("0 - EXIT\n");

}

void emptyGrid(int dimensions){
    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            printf("[ ] ");
        }
    printf("\n");
    }

}
void printGrid(int dimensions, char grid[MAX_ROWS][MAX_COLS]){
    for (int i = 0; i < dimensions; i++){
        char * ptr = grid[i];
        for (int j = 0; j < dimensions; j++, ptr++){
            printf("[%c] ", *ptr);
        }
    printf("\n");
    }
}

void printGridPos(int dimensions, char grid[MAX_ROWS][MAX_COLS], char * pos){
    for (int i = 0; i < dimensions; i++){
        char * ptr = grid[i];
        for (int j = 0; j < dimensions; j++, ptr++){
            if (ptr == pos){
                printf("[%c] ", *ptr);
            } else {
                printf("[ ] ");
            }
        }
    printf("\n");
    }
}


void fillGrid(int dimensions, char grid[MAX_ROWS][MAX_COLS]){
    char symbArr[18] = {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    int countArr[18] = {0};
    srand(time(0));
    for (int i = 0; i < dimensions; i++){
        char * ptr = grid[i];
        for (int j = 0; j < dimensions; j++, ptr++){
            int filled = 0;
            while (filled != 1){
                int pos = rand() % (dimensions*dimensions/2);
                if (countArr[pos]++ < 2){
                    *ptr = symbArr[pos];
                    filled = 1;
                }
            }
        }
    }
}

void setUp(int dimensions, char grid[MAX_ROWS][MAX_COLS]){
        emptyGrid(dimensions);
        fillGrid(dimensions, grid);
}

char * coordinates(int dimensions, char grid[MAX_ROWS][MAX_COLS], int run){
    int coord1, coord2;
    _Bool goAgain;
    char * ptr;
    do{
        goAgain = 0;
        switch (run){
            case 1:
            printf("Enter first coordinates: ");
            break;
            case 2:
            printf("Enter second coordinates: ");
            break;
        }
        scanf("%d %d", &coord1, &coord2);
        if (--coord1 < dimensions && --coord2 < dimensions){
            ptr = &grid[coord1][coord2];
        } else {
            printf("Invalid coordinates. Try again\n");
            goAgain = 1;
        }
    }while(goAgain);
    //run++;
    printGridPos(dimensions, grid, ptr);
return ptr;
}

_Bool compareCoords(char * ptr1, char * ptr2){
    return *ptr1 == *ptr2;
}

void printMatchingPair(int dimensions, char grid[MAX_ROWS][MAX_COLS], char * pair){
    printf("IT'S A MATCH!\n");
    for (int i = 0; i < dimensions; i++){
        char * ptr = grid[i];
        for (int j = 0; j < dimensions; j++, ptr++){
            if (*ptr == *pair){
                printf("[%c] ", *ptr);
            } else {
                printf("[ ] ");
            }
        }
    printf("\n");
    }
}
void printMatches(int dimensions, char grid[MAX_ROWS][MAX_COLS], char * set1, char * set2){
    for (int i = 0; i < dimensions; i++){
        char * ptr = grid[i];
        for (int j = 0; j < dimensions; j++, ptr++){
            if (*set1 == *set2){
                printf("[%c] ", *set1);
            } else {
                printf("[ ] ");
            }
        }
    printf("\n");
    }
}


int playGame (int dimensions, char grid[MAX_ROWS][MAX_COLS]){
    int scoreValue = dimensions*dimensions;
    setUp(dimensions, grid);
    int complete = 0;
    int count = 0;
    
    while (complete != 2){
        int runthrough = 1;
        char * set1 = coordinates(dimensions, grid, runthrough);
        runthrough++;
        char * set2 = coordinates(dimensions, grid, runthrough);
        _Bool correct = compareCoords(set1, set2);
        if (correct){
            complete++;
            printMatchingPair(dimensions, grid, set1);
        } else {
            scoreValue--;
        }
    }
    if (scoreValue > 0){
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
return scoreValue;
}

void sort(int scores[MAX_NAMES], char names[MAX_NAMES][MAX_COLS]){
    _Bool ordered;
    do{
        ordered = 1;
        for(int i = 0; i < MAX_NAMES - 1; i++){
            if(scores[i] > scores[i-1]){
                int temp = scores[i];
                scores[i] = scores[i+1];
                scores[i+1] = temp;
                char * temp1;
                strcpy(temp1, names[i]);
                strcpy(names[i], names[i+1]);
                strcpy(names[i+1], temp1);
                ordered = 0;
            }
        }
    }while(ordered == 0);
}

_Bool fileEmpty(FILE * fp){
    FILE * test = fp;
    char c;
    if(fscanf(test, "%c", &c) == EOF){
        return 1;
    }
return 0;
}

void saveScores1( int score){
    int scores[MAX_NAMES] = {0};
    char names[MAX_NAMES][MAX_COLS];
    char * trash1,* trash2;
    int yes;
    const char * defaultName = "???";
    printf("Would you like to save your score? 1 - y ");
    scanf("%d", &yes);
    if (yes == 1){
        printf("Enter your name: ");
        scanf("%s", names[MAX_NAMES-1]);
        FILE * fp;
        fp = fopen("scores.txt", "w+");
        fscanf(fp, "%s\t%s\n", trash1, trash2);
        for (int i = 0; i < MAX_NAMES-1; i++){
            if (fscanf(fp, "%s\t%d\n", names[i], &scores[i]) == EOF){
                strcpy(names[i], defaultName);
            }
        }
        scores[MAX_NAMES-1] = score;
        fclose(fp);
        fp = fopen("scores.txt", "w");
        sort (scores, names);
        fprintf(fp, "Names\tScores\n");
        for (int i = 0; i < MAX_NAMES; i++){
            fprintf(fp, "%s\t%d\n", names[i], scores[i]);
        }
        fclose(fp);

    }
}

void saveScores(FILE *fp, int scores){
char names[MAX_COLS];


printf("Enter your name:");
scanf("%s", names);
if((fp = fopen("scores.txt", "a")) == NULL)
{
printf("can't open file");

return;
}

for(int index = 0; names[index] !='\0'; index++)
{
fprintf(fp, "%c", names[index]);
}

fprintf(fp, "  %d\n", scores);

fclose(fp);

}
/*****************************/
int readScores(int score[], char nameArr[][MAX_COLS])
{

int numberofscores;

FILE * fp;

fp = fopen("scores.txt", "r");

fscanf(fp, "%s%d", nameArr[10], &score[10]);

fclose(fp);

return numberofscores;
}
/******************************************************************************************************/
void writeScores(int numberofscores, int score[], char nameArr[][MAX_COLS])
{

FILE * fp; 

fp = fopen("scores.txt", "w");

fprintf(fp, "%s  %d\n", nameArr[numberofscores], score[numberofscores]);


fclose(fp);

}

