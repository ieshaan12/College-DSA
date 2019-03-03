#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"quickSort.h"
#include"insertionSort.h"
#include"mergeSort.h"
#include"bubbleSort.h"
void printArr(int arr[], int size)
{for(int i=0;i<size;i++)
	printf("%d,",arr[i]);
printf("\n");
}
int main()
{
	int size;
	scanf("%d",&size);
	int arr[size],arr2[size];
	clock_t start,end;
	float time_taken;
	srand(time(0));
	for(int i=0;i<size;i++)
		arr[i]=rand()%1000;
	//printArr(arr,size);
	printf("\n");

	for(int i=0;i<size;i++)
		arr2[i]=arr[i];
	start=clock();
	quickSort(arr2,0,size-1);
	end=clock();
	time_taken=(float)(end-start)/CLOCKS_PER_SEC;
	printf("Post-quickSort:%lf s\n",time_taken);
	//printArr(arr2,size);
	printf("\n");

	for(int i=0;i<size;i++)
		arr2[i]=arr[i];
	start=clock();
	mergeSort(arr2,0,size-1);
	end=clock();
	time_taken=(float)(end-start)/CLOCKS_PER_SEC;
	printf("Post-mergeSort:%lf s\n",time_taken);
	//printArr(arr2,size);
	printf("\n");

	for(int i=0;i<size;i++)
		arr2[i]=arr[i];
	start=clock();
	InsertionSort(arr2,size);
	end=clock();
	time_taken=(float)(end-start)/CLOCKS_PER_SEC;
	printf("Post-insertionSort:%lf s\n",time_taken);
	//printArr(arr2,size);
	printf("\n");

	for(int i=0;i<size;i++)
		arr2[i]=arr[i];
	start=clock();
	Bubble(arr2,size);
	end=clock();
	time_taken=(float)(end-start)/CLOCKS_PER_SEC;
	printf("Post-bubbleSort:%lf s\n",time_taken);
	//printArr(arr2,size);
	printf("\n");
	
		
return 0;
}
