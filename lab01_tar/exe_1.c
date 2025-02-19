#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

int n;
int s = 0;

printf("Please enter a number between 1 and 20:\n");

scanf("%d", &n);

if((n < 1) || (n > 20)){
	printf("\nPlease run the program again entering a number between 1 and 20\n\n");
	return(1);
}

for(int i = 1; i <= n; i++){
	s = s + i;
}	

printf("%d\n", s);

return(0);
}
