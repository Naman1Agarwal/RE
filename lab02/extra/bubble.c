#include<string.h>
#include <stdio.h>
#include "bubble.h"

void sort(int *arr)
{
	int temp, size=100;
	int i,j;
	i = 0;
	
outer_loop:
	if ( i < size){
		j = size-1;
		goto inner_loop; 
	}
	return;


inner_loop:
	if (j > i){
		goto swap;
	}
	i++;
	goto outer_loop;

swap:
	if (arr[j] < arr[j-1]){
		temp = arr[j-1];
		arr[j-1] = arr[j];
		arr[j] = temp;
	}    
	j--;
	goto inner_loop; 
	

}
