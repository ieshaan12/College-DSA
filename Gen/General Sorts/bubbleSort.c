#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"bubbleSort.h"
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

