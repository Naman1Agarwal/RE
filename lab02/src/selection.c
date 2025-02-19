#include<stdio.h>
#include<stdlib.h>
#include "selection.h"

int main(int argc, char *argv[])
{
    int arr[100];
    int i=0;

    printf("Initial list: \n");
    before:
    arr[i] = (rand()%100) + 1;

    if(i<100)
    {
        printf("%d\n", arr[i]);
        i++;
        goto before;
    }

    sort(arr);

    printf("Sorted list: \n");
    i=0;
    after:

    if(i<100)
    {
        printf("%d\n", arr[i]);
        i++;
        goto after;
    }

    return(0);
}
