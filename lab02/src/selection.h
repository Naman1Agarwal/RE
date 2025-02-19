#include<stdio.h>
#include<stdlib.h>

void sort(int *array)
{
	int n, c, d, position, swap;
	n=100;
	c = 0;
outer_loop:   
	if (c < n - 1){
		position = c;
		d = c+1;
		goto inner_loop;
	}
	return;

inner_loop:
	if (d < n){
		goto inner_if;
	}
	goto second_if;

inner_if:
	if(array[position] > array[d]){
		position = d;
	}
	d++;
	goto inner_loop;

second_if:
	if (position != c)
	{
		swap = array[c];
		array[c] = array[position];
		array[position] = swap;
	}
	c++;
	goto outer_loop;
}
