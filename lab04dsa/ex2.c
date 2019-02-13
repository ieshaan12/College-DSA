#include<stdio.h>
#include<stdlib.h>
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
/*
int main()
{int m=12000;
//void *ptr=myalloc(100);
//myfree(ptr);
//printf("%p\t%d\n",ptr,heap_size);
while(m!=0){
scanf("%d",&m);
int *ptr=(int *)myalloc(m*sizeof(int));
printf("%p\t%p\n",&ptr[0],&ptr[m-1]);
unsigned int s=(&ptr[m-1]-&ptr[0]);
printf("%d\t%u\n",heap_size,s);
myfree(ptr);
}
return 0;
}*/
