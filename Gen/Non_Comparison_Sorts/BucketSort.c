#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start,end;
void InsertionSort(float arr[],int size)
{
	for(int i=1;i<size;i++)
		{float check=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>check)
			{arr[j+1]=arr[j];
			j--;
			}
		arr[j+1]=check;
		}
}

int main()
{start=clock();
int size=1000;
float arr[size];
float bucket[size][size];
for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
		{bucket[i][j]=-1;}
srand(time(0));
for(int i=0;i<size;i++)
	{float t=(float)(rand()%100)/100;
	arr[i]=t;
	}
for(int i=0;i<size;i++)
	{printf("%.2f,",arr[i]);}
printf("\n");
for(int i=0;i<size;i++)
	{float slot=arr[i]*10;
	for(int j=0;j<size;j++)
		{if(bucket[(int)slot][j]==-1)
			{bucket[(int)slot][j]=arr[i];
			break;}
		}
	}
for(int i=0;i<size;i++)
	{InsertionSort(bucket[i],size);
		{for(int j=0;j<size;j++)
			if(bucket[i][j]!=-1)
				printf("%.2f,",bucket[i][j]);	
		}
	}
printf("\n");
end=clock();
float time_taken=(float)(end-start)/CLOCKS_PER_SEC;
printf("Time Taken for bucket sort: %f",time_taken);
}
			
