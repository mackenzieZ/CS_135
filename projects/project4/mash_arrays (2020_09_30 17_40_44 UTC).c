//Purpose: Perform the 'mash' game with randomly predicted futures
//Name: mash_arrays.c
//Author: Mackenzie Zappe
//Date: 10/10/19

#include <stdio.h>
#include<stdlib.h>
#include <time.h>


int main(void){

int size = 0;
printf("How many choices do you want to play with? ");
scanf("%d", &size);

//spouse value array
char spouseAr[size];
printf("Who do you want to marry?\n");
printf("(enter %d intitials)", size);
for(int index = 0; index < size; index++){
    scanf(" %c", &spouseAr[index]);
}
//kid amount array
int kidsAr[size];
printf("How many kids do you want?\n");
printf("(enter %d whole numbers)", size);
for(int index = 0; index < size; index++){
    scanf("%d", &kidsAr[index]);
}
//income value array 
double incomeAr[size];
printf("How much money do you want?\n");
printf("(enter %d decimal amounts)", size);
for(int index = 0; index < size; index++){
    scanf("%lf", &incomeAr[index]);
}

//random number generator
srand(time(0));
int randomNumberS = (rand() % size) % size;
int randomNumberK = (rand() % size) % size;
int randomNumberI = (rand() % size) % size;

//shelter variable uses switch statement to determine shelter for final option
int shelter = (rand() % size) % 3;

//printing the option together
switch(shelter){
    case 1: printf("You live in a House.\n");
    break;
    case 2: printf("You live in an Apartment.\n");
    break;
    case 0: printf("Ypu live in a Mansion.\n");
    break;
}
printf("You make %.2lf dollars per year.\n", incomeAr[randomNumberI]);
printf("You're married to %c and have %d kids.\n", spouseAr[randomNumberS], kidsAr[randomNumberK]);

return 0;
}