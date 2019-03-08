#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Sort.h"
void selection(int arr[],int size)
{
for(int i=0;i<size;i++)
	{int pos=i;
		for(int j=i;j<size;j++)
			{if(arr[j]<arr[pos])
				{pos=j;}
			}
	int t=arr[pos];
	arr[pos]=arr[i];
	arr[i]=t;
	}
}
