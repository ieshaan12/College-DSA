#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"insertionSort.h"
void InsertionSort(int arr[],int size)
{
	for(int i=1;i<size;i++)
		{int check=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>check)
			{arr[j+1]=arr[j];
			j--;
			}
		arr[j+1]=check;
		}
}

