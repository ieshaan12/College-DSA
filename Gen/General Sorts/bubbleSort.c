#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printArr(int arr[],int size)
{for(int i=0;i<size;i++)
	{printf("%d,",arr[i]);
	}
	printf("\n");
}
void Bubble(int a[],int size)
{for(int i=0;i<size;i++)
	{for(int j=0;j<size;j++)
		{if(a[i]<a[j])
			{int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			}
		}
	}
}
int main()
{int size=100;
int arr[size];
srand(time(0));
for(int i=0;i<size;i++)
	{arr[i]=rand()%100;
	}
	printArr(arr,size);
Bubble(arr,size);
printf("Post-BubbleSort\n");
	printArr(arr,size);
	
	return 0;
}
