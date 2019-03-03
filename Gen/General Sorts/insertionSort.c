#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printArr(int arr[],int size);
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
void printArr(int arr[],int size)
{for(int i=0;i<size;i++)
	{printf("%d,",arr[i]);
	}
	printf("\n");
}

int main()
{int size=100;
int arr[size];
srand(time(0));
for(int i=0;i<size;i++)
	{arr[i]=rand()%100;
	}
	printArr(arr,size);
InsertionSort(arr,size);
printf("Post-insertionsort\n");
	printArr(arr,size);
	
	return 0;
}
