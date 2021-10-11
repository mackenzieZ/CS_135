//Purpose: User enters data into a table and then the data is analyized with a menu.
//Name: data_analysis.c
//Author: Mackenzie Zappe
//Date: 10/21/19

#include <stdio.h>

int countValues(int rows, int cols, double arr[][cols], double upper, double lower);
_Bool hasValues(int rows, int cols, double arr[][cols], double lookingValue);
double displayValues(int rows, int cols, double arr[][cols]);

int main(){

int rows, cols;
double lower, upper;
double lookingValue;

printf("How many rows do you have?");
scanf("%d", &rows);
printf("How many columns do you have?");
scanf("%d", &cols);


double dataArr [rows][cols];
for (int indexR = 0; indexR < rows; indexR++){
    printf("Please enter a row of data");
    for(int indexC = 0; indexC < cols; indexC++){
        scanf("%lf", &dataArr[indexR][indexC]);
    }
}

int menuInput;
printf("***Data Analysis***\n");
do{
printf("1 - Find Count of Values in a Range\n");
printf("2 - Find a Value\n");
printf("3 - Display Data\n");
printf("0 - EXIT\n");
scanf("%d", &menuInput);

if(menuInput < 0 || menuInput > 3){
    printf("Invalid menu input. Try Again.\n");
}

switch(menuInput) {
    case 1:
        printf("Enter the minimum of your range:");
        scanf("%lf", &lower);
        printf("Enter the maximum of your range:");
        scanf("%lf", &upper);

        if(lower >= upper){
            printf("Invalid Range. Try Again.\n");
        }else{
            printf("\nThere are %d values between %.2lf and %.2lf.\n", countValues(rows, cols, dataArr, lower, upper), lower, upper);
        }
    break;
    case 2:
        
        printf("What value are you looking for?");
        scanf("%lf", &lookingValue);

        if(hasValues(rows, cols, dataArr, lookingValue)){
            printf("%.2lf is in the data.\n", lookingValue);
        }else{
            printf("%.2lf was not found.\n", lookingValue);
        }
        
    break;
    case 3:
        displayValues(rows, cols, dataArr);
    break;
}

}while(menuInput != 0);

return 0; 
}

int countValues(int rows, int cols, double arr[rows][cols], double lower, double upper){
        int count = 0;
       
        for(int indexR = 0; indexR < rows; indexR++){
            for(int indexC = 0; indexC < rows; indexC++){
                if(arr[indexR][indexC] < upper && arr[indexR][indexC] > lower){
                    count++;
                }
            }
    
        }
return count;
}
_Bool hasValues(int rows, int cols, double arr[rows][cols], double lookingValue){
        _Bool found = 0;

        for(int indexR = 0; indexR < rows; indexR++){
            for(int indexC = 0; indexC < rows; indexC++){
                if(arr[indexR][indexC] == lookingValue){
                    found = 1; 
                }
            }
   
        }
return found;
}
double displayValues(int rows, int cols, double arr[rows][cols]){
    printf("|||Your Data|||\n");
    for(int indexR = 0; indexR < rows; indexR++){
        for(int indexC = 0; indexC < rows; indexC++){
            printf("%.2lf\t", arr[indexR][indexC]);
        }
    printf("\n");
    }
}