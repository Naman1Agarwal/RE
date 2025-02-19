#include<string.h>

void sort(int *arr)
{
    int temp, size=100;
    int i,j;

    for(i=0;i<size;i++){
        for(j=size-1; j>i; j--){
            if(arr[j]<arr[j-1]){
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }

}

