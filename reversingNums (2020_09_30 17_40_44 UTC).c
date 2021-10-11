#include <stdio.h>
#define SIZE 10
int main(void)
{
char digits[SIZE];
char *ptr; 

printf("Enter %d numbers:", SIZE);
for(ptr = digits; ptr < digits + SIZE; ptr++){
	scanf("%c", ptr);
}
printf("In reverse order:");
for (ptr = digits + (SIZE-1); ptr >= digits; ptr--){
	printf("%c ", *ptr);
}
printf("\n");
return 0;
}