#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exe_2.h"

#define LENGTH 20

int main()
{

char word[LENGTH] = {};
char hidden_word[LENGTH] = WORD;

printf("Please enter a password:\n");
scanf("%s", word);


    if(strcmp(word, hidden_word) == 0){
	printf("Success\n");
    }

    else{
	printf("Failure\n");
    }


return(0);
}
