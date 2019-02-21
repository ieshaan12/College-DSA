#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "ex2.h"
int heap_size=0;
void *myalloc(int size)
{
void *ptr=malloc(size+sizeof(int));
*(int *)ptr=size;
heap_size=heap_size+size;
return ptr+sizeof(int);
}

void myfree(void* ptr)
{int size_del=*(int *)(ptr-sizeof(int));
//printf("%d\n",size_del);
heap_size=heap_size-size_del;
ptr=ptr-sizeof(int);
free(ptr);
}

int main()
{int m;
srand(time(0));
int *A=NULL;
do
	{
	m=rand()%15000+10000;
	A=(int *)myalloc(m);
	printf("%u\t%u\t%d\n",&A[0],&A[m-1],m);
	myfree(A);
	}while(A);
}
