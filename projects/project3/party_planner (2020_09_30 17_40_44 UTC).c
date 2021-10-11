//Purpose: track party supplies and compare to budget
//Name: party_planner.c
//Author: Mackenzie Zappe
//Date: 09/21/19

#include <stdio.h>

int main(void){

int quantCobbler, quantCake, quantMushrooms;
int cobblerUserInput, cakeUserInput, mushroomsUserInput;
double priceCobbler = 3.00, priceCake = 5.50, priceMushrooms = 7.75;
double budget;
double costCobbler, costCake, costMushrooms, costTotal; 
int menuInput;



do{
    printf("1-update peach cobbler\n");
    printf("2-update devil's food cake\n");
    printf("3-update mushroom caps\n");
    printf("4-update budget\n");
    printf("5-order supplies\n");
    printf("6-display amounts\n");
    printf("0-exit\n");
    scanf("%d", &menuInput);

    if(menuInput > 6 || menuInput < 0){
    printf("Please enter a valid menu input\n");
    }

    costCobbler = quantCobbler * priceCobbler;
    costCake = quantCake * priceCake;
    costMushrooms = quantMushrooms * priceMushrooms;
    costTotal = costCobbler + costCake + costMushrooms;


    switch(menuInput){
        case 1:
            do{
            printf("Enter a quantity for peach cobbler:\n");
            scanf("%d", &cobblerUserInput);
            quantCobbler += cobblerUserInput;
            if(quantCobbler <0){
                printf("Cannot have negative quantities. Try again.\n");
                quantCobbler -= cobblerUserInput;
            }
            } while (quantCobbler < 0 );
            break;
        case 2:
            do{
            printf("Enter a quantity for devil's food cake:\n");
            scanf("%d", &cakeUserInput);
            quantCake += cakeUserInput;
            if(quantCake <0){
                printf("Cannot have negative quantities. Try again.\n");
                quantCake -= cakeUserInput;
            }
            } while (quantCake < 0 );
            break;
        case 3:
            do{
            printf("Enter a quantity for mushroom caps:\n");
            scanf("%d", &mushroomsUserInput);
            quantMushrooms += mushroomsUserInput;
            if(quantMushrooms <0){
                printf("Cannot have negative quantities. Try again.\n");
                quantMushrooms -= mushroomsUserInput;
            }
            }while(quantMushrooms < 0);
            break;
        case 4:
            do{
            printf("What's your budget?\n");
            scanf("%lf", &budget);
            if (budget < 0 ){
                printf("Cannot have a negative budget.Try again.\n");
                budget -= budget;
            }
            }while (budget < 0);
            break;
        case 5: 
            if(costTotal >= budget){
                printf("You can't afford your supplies. Please adjust your quantities.\n");
            }else if (costTotal == 0){
                printf("No items were included in your order\n");
            }else{
                printf("Your supplies have been ordered!\n");
            }
            break;
        case 6:
            printf("ITEM\t\t\tPRICE  AMOUNT  TOTAL\n");
            printf("peach cobbler\t\t %.2lf\t  %d\t %.2lf\n", priceCobbler, quantCobbler, costCobbler);
            printf("devil's food cake\t %.2lf\t  %d\t %.2lf\n", priceCake, quantCake, costCake);
            printf("mushroom caps\t\t %.2lf\t  %d\t %.2lf\n", priceMushrooms, quantMushrooms, costMushrooms);
            printf("ALL\t\t\t\t\t %.2lf\n", costTotal);
            printf("YOUR BUDGET:\t\t\t\t%.2lf\n", budget);
            break;
    
            
            


    }

}while(menuInput != 0);


    return 0;
}