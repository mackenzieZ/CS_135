//Purpose: Build your own adventure game
//Name: adventure.c
//Author: Mackenzie Zappe
//Date: 09/12/2019

#include <stdio.h>

int main(void){

int health = 10, chest, bag, ogre;
double wealth = 0.0;
_Bool sword = 0, shield = 0;

printf("***CHOOSE YOUR OWN ADVENTURE***\n");

//Encounter 1 w/ chest
printf("You're walking through the woods and come upon a chest.\n Do you open it? 1-yes 2-no\n");
scanf("%d", &chest);
if (1 % chest == 0){
    wealth = wealth + 3.75;
    sword = 1;
    printf("You found a sword worth 3.75 Wealth Points!\n");
    printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);

}else{
    --health;
    printf("As you pass the chest, you stub your toe on it and lose a health point.\n");
    printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);
}

//Encounter 2 w/ bag
printf("As you pass a pond, you notice a bag on the ground.\n Do you open it? 1-yes 2-no\n");
scanf("%d", &bag);
if (1 % bag == 0){
    wealth = wealth + 5.15;
    shield = 1;
    printf("You found a shield worth 5.15 Wealth Points!\n");
    printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);

}else{
    --health;
    printf("While passing the pond, your foot gets wet and eventually you get a blister.\n");
    printf("Lose a health point.\n");
    printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);
}

//Encounter 3 w/ ogre
printf("A giant ogre approaches!\n Do you fight or flee? 1-fight 2-flee\n");
scanf("%d", &ogre);
if(1 % ogre == 0){                                                              //fight
    if(sword && shield){                                            //have both shield and sword
        health = health + 12;
        printf("You vanquish the loathsome ogre with sword and shield!!\n");
        printf("You steal his life force and add it to your own!\n");
        printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);
    }else if (!shield) {                                                  // no shield
         if (!sword){                                                     // no shield or sword
            health = 0;
            printf("You can't fight or defend yourself. :'(\n");
            printf("Plus, you have a stubbed toe and a blister. You die!\n");
            printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);
            
         }else{
        health = 0;
        printf("You have a sword to fight with! But no shield. :(\n");
        printf("You die but take the ogre down with you!\n");
        printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);
         }
    }else{                                                                  // no sword
        printf("You have a shield but cannot fight!\n");
        printf("At least you live to fight another day!\n");
        printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);
    }
}else{                                                                              //flee
    health = 0;
    printf("As you turn to run, you trip on a log and the ogre steps on you.\n You die!\n");
    printf("**********\nWealth: %.2lf\nHealth: %d\n**********\n", wealth, health);
}

//EndGame stats
if (health > 10 && wealth > 4.25){
    printf("You win! CONGRATULATIONS!\n");

}else{
    printf("You lose! Try again!\n");
}

return 0;
}