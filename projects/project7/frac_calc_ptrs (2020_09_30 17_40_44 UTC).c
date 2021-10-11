//Purpose: Fraction calculator using pointers and functions 
//Name: frac_calc_ptrs.c 
//Author: Mackenzie Zappe
//Date: 11/12/2019

#include <stdio.h>

#define SIZE 100

int getMenuChoice ();
void getFraction(int *num, int *denom);
void addFraction(int num1, int denom1, int num2, int denom2, int *finalN, int *finalD);
void subtractFraction(int num1, int denom1, int num2, int denom2, int *finalN, int *finalD);
void multiplyFraction(int num1, int denom1, int num2, int denom2, int *finalN, int *finalD);
void dividesFraction(int num1, int denom1, int num2, int denom2, int *finalN, int *finalD);
void reduceFraction(int *reducedN, int *reducedD);
void printResult(int *resultN, int *resultD);


int main(){
    int userChoice, num1, num2, denom1, denom2;
    int totalNum, totalDenom;

    do{
    userChoice = getMenuChoice();

    switch(userChoice){
        case 1:
        getFraction(&num1, &denom1);
        getFraction(&num2, &denom2);
        addFraction(num1, denom1, num2, denom2, &totalNum, &totalDenom);
        printResult(&totalNum, &totalDenom);
        break;
        case 2:
        getFraction(&num1, &denom1);
        getFraction(&num2, &denom2);
        subtractFraction(num1, denom1, num2, denom2, &totalNum, &totalDenom);
        printResult(&totalNum, &totalDenom);
        break;
        case 3:
        getFraction(&num1, &denom1);
        getFraction(&num2, &denom2);
        multiplyFraction(num1, denom1, num2, denom2, &totalNum, &totalDenom);
        printResult(&totalNum, &totalDenom);
        break;
        case 4:
        getFraction(&num1, &denom1);
        getFraction(&num2, &denom2);
        dividesFraction(num1, denom1, num2, denom2, &totalNum, &totalDenom);
        printResult(&totalNum, &totalDenom);
        break;

    }
    }while(userChoice != 0 );



return 0;
}

int getMenuChoice(){
    int menuInput;
    printf("***FRACTION CALCULATOR***\n");
    printf("1 - addition\n");
    printf("2 - subtraction\n");
    printf("3 - multiplication\n");
    printf("4 - division\n");
    printf("0 - exit\n");
    scanf("%d", &menuInput);
return menuInput; 
}

void getFraction(int *num, int *denom){
    printf("Enter a fraction #/#\n");
    scanf("%d/%d", num, denom);

}
void printResult(int *resultN, int *resultD){
    printf("*RESULT*\n %d/%d\n", *resultN, *resultD);
}

void addFraction(int num1, int denom1, int num2, int denom2, int *finalN, int *finalD){
    int lcd;
    if(denom1 != denom2){
        lcd = denom1 * denom2;
        num1 *= denom2;
        num2 *= denom1;
        *finalN = num1 + num2;
        *finalD = lcd;
    }else{
        *finalN = num1 + num2;
        *finalD = denom1;
        reduceFraction(finalN, finalD);
    }
    
}
void subtractFraction(int num1, int denom1, int num2, int denom2, int *finalN, int *finalD){
    int lcd;
    if(denom1 != denom2){
        lcd = denom1 * denom2;
        num1 *= denom2;
        num2 *= denom1;
        *finalN = num1 - num2;
        *finalD = lcd;
    }else{
        *finalN = num1 - num2;
        *finalD = denom1;
    }
    reduceFraction(finalN, finalD);
}

void reduceFraction(int *reducedN, int  *reducedD){
    for(int dividen = *reducedD; dividen > 1; dividen--){
        if(*reducedD % dividen == 0 && *reducedN % dividen == 0){
            *reducedD /= dividen;
            *reducedN /= dividen;
        }
    }
       
        
    
}
void multiplyFraction(int num1, int denom1, int num2, int denom2, int *finalN, int *finalD){
    *finalN = num1 * num2;
    *finalD = denom1 * denom2;
    reduceFraction(finalN, finalD);
}
void dividesFraction(int num1, int denom1, int num2, int denom2, int *finalN, int *finalD){
    *finalN = num1 * denom2;
    *finalD = denom1 * num2;
    reduceFraction(finalN, finalD);
}