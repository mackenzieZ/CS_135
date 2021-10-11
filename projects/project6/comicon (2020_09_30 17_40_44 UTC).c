//Purpose: Welcome Members of Comicon with badge creation and line placement 
//Name: comicon.c 
//Author: Mackenzie Zappe
//Date: 10/24/19

#include <stdio.h>
#define STRING_SIZE_MAX 101

void getstr(char nameArr[]);
int strlength(char nameArr[]);
int strcompare(char nameArr1[], char nameArr2[]);

int main(){
    char first1[STRING_SIZE_MAX];
    char last1[STRING_SIZE_MAX];
    
    char first2[STRING_SIZE_MAX];
    char last2[STRING_SIZE_MAX];

    printf("**Welcome to Comicon**\n");

    printf("Please enter your Name 1:");
    getstr(first1); getstr(last1);
    
    printf("Please enter your Name 2:");
    getstr(first2); getstr(last2);
    
    int length1 = strlength(first1) + 1 + strlength(last1); 
    int length2 = strlength(first2) + 1 + strlength(last2);
    
    if(length1 > 15){
        printf("Name 1 has too many characters for the badge.\n");
    }else{
        printf("Name 1 will fit on the badge.\n");
    }

    if(length2 > 15){
        printf("Name 2 has too many characters for the badge.\n");
    }else{
        printf("Name 2 will fit on the badge.\n");
    }

    switch(strcompare(last1,last2)){
        case 1: 
            printf("%s %s should stand first in line.\n", first1, last1);
        break;
        case -1:
            printf("%s %s should stand first in line.\n", first2, last2);
        break;
        case 0:
            printf("%s %s and %s %s are at the same place in line.\n", first1, last1, first2, last2);
        break;
    
    }
    

return 0;     
}

void getstr(char nameArr[]){

    scanf("%s", nameArr);

}

int strlength(char nameArr[]){
    int index = 0;
    while(nameArr[index++] != '\0'){
    }
return index;    
}
int strcompare(char nameArr1[], char nameArr2[]){
    int index = 0;
    
    if (nameArr1[index] == nameArr2[index]){
        return 0;
    }else if (nameArr1[index] <= nameArr2[index]){
        return 1;
    }else{
        return -1;
    }
}