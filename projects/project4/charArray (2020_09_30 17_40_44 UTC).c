#include <stdio.h>
#define SIZE 5
int main (){

char array[SIZE];

printf("Enter char values\n");
for(int index = 0; index < SIZE; index++){
    scanf(" %c", &array[index]);
}

for(int index = 0; index < SIZE; index++){
    printf("%c\n", array[index]);
}

return 0; 
}