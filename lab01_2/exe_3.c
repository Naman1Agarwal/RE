#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
int arr[argc];
int temp, size;
int i,j;

size = argc-1;
for(i=1;i<argc;i++){
	if(atoi(argv[i]) == 0){
		printf("Please run program again with integers as input\n");
		return(0);
	}
	arr[i-1]=atoi(argv[i]);
}
for(i=0;i<size;i++){
	for(j=size-1; j>i; j--){
 		if(arr[j]<arr[j-1]){
			temp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=temp;
		}
	}
}

for(i=0;i<size;i++){
	printf("%d\n", arr[i]);
}
}

		
