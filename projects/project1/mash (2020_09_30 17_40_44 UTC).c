// Name: mash.c
//Purpose: Allow user to play a simplified version of MASH game.
//Author: Mackenzie Zappe
//Date: 09/05/2019

#include <stdio.h>

int main (void){

int kid1, kid2, kid3;
char spouse1, spouse2, spouse3;
double income1, income2, income3;

//User Prompts and receiving inputs
printf("Who do you want to marry\?\n(Enter 3 first name initials)");
scanf("%c %c %c", &spouse1, &spouse2, &spouse3);
printf("How many kids do you want\?\n(Enter 3 whole numbers)");
scanf("%d %d %d", &kid1, &kid2, &kid3);
printf("How much money do you want\?\n(Enter 3 decimal values)");
scanf("%lf %lf %lf", &income1, &income2, &income3);

//Display of Options to user

printf("\nM*A*S*H\n");

printf("Option 1:\nYou live in a Mansion.\nYou make $%.2lf dollars per year.\n", income1);
printf("You're married to %c and have %d kid(s).\n\n", spouse1, kid1);
printf("Option 2:\nYou live in an Apartment.\nYou make $%.2lf dollars per year.\n", income2); 
printf("You're married to %c and have %d kid(s).\n\n", spouse2, kid2);
printf("Option 3:\nYou live in a House.\nYou make $%.2lf dollars per year.\n", income3);
printf("You're married to %c and have %d kid(s).\n\n", spouse3, kid3);


    return 0;
}