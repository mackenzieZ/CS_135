//Purpose: making a memory matching game for our final project
//Name: memory.c
//Authors: Mackenzie Zappe and Logan Johnson
//Date: 11/30/19
 
#include <stdio.h> 
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <stdlib.h>
 
 
 
#define ROWS 100
#define COLS 100
#define NUM_SCORES 11
 
 
int playGame(int level, int size, int dimensions, char array[][COLS]);
int declareLevel ();
void displayMenu();
void setUp1(int size, int dimensions, char array[][COLS]);
void setUp2(int size, int dimensions,  char array[][COLS]);
void setUp3(int size,  int dimensions, char array[][COLS]);
void printGrid(int size, char array[][COLS]);
void saveScores(int score[], char * nameArr[COLS], int finalScore, int count);
void toFile( int score[], char * nameArr[COLS], int count);
void sortScores(int numscores, int score[], char * nameArr[COLS], int finalScore, int count);
int scoresInFile();
 
 
 
 
/*void saveScores(FILE *scores, int score);
void viewScores();
*/
 
 
int main(int arg, char *argv[]){
    int userInput, difficulty, save, finalScore, quantScores = 0, count = 0;
    char playingGrid[ROWS][COLS];
    int scoreArr[COLS]; 
    char * nameArr[COLS];
    const int total1 = 4, total2 = 16, total3 = 36;
    const int  dim1 = 2, dim2 = 4, dim3 = 6;
    do{
        displayMenu();
        scanf("%d", &userInput);
            switch(userInput){
                    case 1:
                        printf("Enter difficulty:");
                        scanf("%d", &difficulty);
                        if(difficulty > 0 && difficulty < 4){
                        switch(difficulty){
                            case 1:
                            setUp1(total1, dim1, playingGrid);
                            printGrid(dim1, playingGrid);
                            finalScore = playGame(difficulty, total1, dim1, playingGrid);
                            printf("Your score is: %d\n", finalScore);
                            break;
                            case 2:
                            setUp2(total2, dim2, playingGrid);
                            printGrid(dim2, playingGrid);
                            finalScore = playGame(difficulty, total2, dim2, playingGrid);
                            break;
                            case 3:
                            setUp3(total3, dim3, playingGrid);
                            printGrid(dim3, playingGrid);
                            finalScore = playGame(difficulty, total3, dim3, playingGrid);
                            break;
                            default: 
                            printf("Inappropriate level selected\n");
                            break;
                        }
                        
                        if(finalScore > 0){
                            printf("You win!\n");
                        }else{
                            printf("You Lose\n");
 
                        }
                        printf("Do you want to save your score? 1 -yes:");
                        scanf("%d", &save);
                        if(save){
			                if(scoresInFile() > 10){
			                    quantScores = scoresInFile();
			            }
			            sortScores(quantScores, scoreArr, nameArr, finalScore, count);
                        }
                        }else{
                            printf("Invalid Difficulty. Try again.\n");
                        }
                    break;
                    case 2:
                        
			//printf("%s   %d\n", nameArr[index], scoreArr[index]);

                    break;
            }
    }while(userInput !=0);
 
    
 
return 0; 
}
/******************************************************************************************************/
int declareLevel (){
    int level;
    printf("What difficulty do you want?");
        scanf("%d", &level);

        
return level;
}
/******************************************************************************************************/
void displayMenu(){
        printf("***MEMORY!****\n");
        printf("1 - Play Game\n");
        printf("2- Check Scores\n");
        printf("0 -EXIT\n");
    
}
/******************************************************************************************************/
int playGame(int level, int size, int dimensions, char array[][COLS]){
    int cd1a, cd2a, cd1b, cd2b;
    int input1a, input1b, input2a, input2b; 
    int moves = 0, levelScore;
    _Bool matched[dimensions][dimensions];
    int paired[dimensions][dimensions];
    int solved = 0;
 
    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            matched[i][j] = 0;
            paired[i][j] = 0;
            
        }
    }
    
 
    do{
        /*
    printf("Enter first coordinates:\n");
    scanf("%d %d", &input1a, &input1b);
     if(input1a > dimensions || input1b > dimensions){
        printf("Coordinates out of Bounds.\n");
        printf("Enter first coordinates:\n");
        scanf("%d %d", &input1a, &input1b);
    }
    printf("Enter second coordinates:\n");
    scanf("%d %d", &input2a, &input2b);
    if(input2a > dimensions || input2b > dimensions){
        printf("Coordinates out of Bounds.\n");
        printf("Enter second coordinates:\n");
        scanf("%d %d", &input2a, &input2b);
    }
 
   
    
    cd1a = input1a -1;
    cd1b = input1b -1;
    cd2a = input2a -1;
    cd2b = input2b -1;
 
    
    if(array[cd1a][cd1b] != array[cd2a][cd2b]){
        moves++;
        printf("Not Matched\n");
        for(int i = 0; i < dimensions; i++){
            for(int j = 0; j < dimensions; j++){
                if(i == cd1a && j == cd1b || i == cd2a && j == cd2b){
                    printf("[ %c ] ", array[i][j]);
                }else{
                    printf("[   ] ");
                }
            }
        printf("\n");
        }
        
    }else{
        printf("Matched!\n");
        matched[cd1a][cd1b] = 1;
        matched[cd2a][cd2b] = 1;
        paired[cd1a][cd1b] = 1;
        paired[cd2a][cd2b] = 1;
    
        
        for(int i = 0; i < dimensions; i++){
            for(int j = 0; j < dimensions; j++){
                if(matched[i][j] == 1){
                printf("[ %c ] ", array[i][j]);
                }else{
                    printf("[   ] ");
                }
            }
            printf("\n");
        }
        
        for(int i = 0; i < dimensions; i++){
            for(int j = 0; j < dimensions; j++){
                if(paired[i][j] == 1){
                solved += paired[i][j];
                paired[i][j] = 0;
                }
            }
        }
    }
    
    
    */
    solved =4;
    }while(solved != size);
    
    levelScore = size - moves;
    
    
 
return levelScore;
}
/******************************************************************************************************/
void setUp1(int size, int dimensions, char array[][COLS]){
    char symbolArr[size/2 + 1];
    strcpy(symbolArr, "!\"");
    int countArr[size/2];
    for(int i = 0; i < size/2; i++){
        countArr[i] = 0;
    }
    int index = 0;
    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            index = rand() % (size/2);
            if(countArr[index] < 2){
                array[i][j] = symbolArr[index];
                countArr[index]++;
                index = 0;
            }else{
                j--;
            }
            
        }
    }
}
/******************************************************************************************************/
void setUp2(int size, int dimensions,  char array[][COLS]){
    char symbolArr[size/2 +1];
    strcpy(symbolArr, "!\"&=#^/)");
    int countArr[size/2];
    for(int i = 0; i < size/2; i++){
        countArr[i] = 0;
    }
    int index = 0;
 
        for(int i = 0; i < dimensions; i++){
            for(int j = 0; j < dimensions; j++){
                index = rand() % (size/2);
                if(countArr[index] < 2){
                    array[i][j] = symbolArr[index];
                    countArr[index]++;
                }else{
                    j--;
                }
            }
        }
 
}
/******************************************************************************************************/
void setUp3(int size, int dimensions, char array[][COLS]){
    char symbolArr[size/2 +1];
    strcpy(symbolArr, "!\"&=#^/)(12.,$@+-?");
    int countArr[size/2];
    for(int i = 0; i < size/2; i++){
        countArr[i] = 0;
    }
    int index = 0;
 
        for(int i = 0; i < dimensions; i++){
            for(int j = 0; j < dimensions; j++){
                index = rand() % (size/2);
                if(countArr[index] < 2){
                    array[i][j] = symbolArr[index];
                    countArr[index]++;
                }else{
                    j--;
                }
            }
        }
 
}
/******************************************************************************************************/
void printGrid(int size, char array[][COLS]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("[    ] ");
        }
        printf("\n");
    }
    printf("\n");
}
/******************************************************************************************************/
 
//fix this function

void saveScores(int score[], char * nameArr[COLS], int finalScore, int count)
{



printf("Enter your name");

scanf("%s", nameArr[count]);

score[count] = finalScore;

count++;



}
/******************************************************************************************************/
void toFile(int score[], char * nameArr[COLS], int count)
{

FILE *fp; 
fp = fopen("scores.txt", "a");

for(int i = 0; i < count; i++){
	fprintf(fp, "%s   %d\n", nameArr[count-1], score[count-1]);
}


fclose(fp);


}
/******************************************************************************************************/
void sortScores(int numScores, int score[], char * nameArr[COLS], int finalScore, int count){

_Bool ordered;

saveScores(score, nameArr, finalScore, count);

do{

ordered = 1;



for(int i =0; i < numScores; i++){
    if(score[i] >score[i+1]){
        int tempNum;
        char tempNames[COLS];
        tempNum = score[i];
        score[i] = score[i+1];
        score[i+1] = tempNum;
        strcpy(tempNames,nameArr[i]);
        strcpy(nameArr[i], nameArr[i+1]);
        strcpy(nameArr[i+1], tempNames);
        ordered = 0;
    }
}

}while(ordered ==0);

if(numScores<10)
{
toFile(score, nameArr, count);
}

}
/******************************************************************************************************/
int scoresInFile()
{
FILE *fp;
int numScores = 0;
char current;
fp = fopen("scores.txt", "rw");

while(fscanf(fp, "%c", &current) != EOF){
    if(current == '\n'){
        numScores++;
    }

}

printf("Number in file: %d\n", numScores);

fclose(fp);

return numScores;
}