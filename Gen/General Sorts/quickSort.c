#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"quickSort.h"
int partition(int arr[], int low,int high)
{
int i=low-1;
int pivot=arr[high];
int j=low;
while(j<=high-1)
	{
	if(arr[j]<=pivot)
		{i++;
		int t=arr[i];
		arr[i]=arr[j];
		arr[j]=t;
		}
	j++;
	}
int t=arr[i+1];
arr[i+1]=arr[high];
arr[high]=t;
return i+1;
}
int quickSort(int arr[],int low,int high)
{
if(low<high)
	{
	int pi=partition(arr,low,high);
	//printArr(arr,10);
	quickSort(arr,low,pi-1);
	quickSort(arr,pi+1,high);
	}
}


