#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct Emp{
char name[10];
int id;
};
void printEmp(struct Emp arr[],int size)
{for(int i=0;i<size;i++)
	{printf("%s,%d\n",arr[i].name,arr[i].id);
	}
}
int partition(struct Emp arr[],int low,int high)
{struct Emp pivot=arr[high];
int top=low-1;
for(int i=low;i<high;i++)
	{if(arr[i].id<=pivot.id)
		{top++;
		struct Emp t=arr[i];
		arr[i]=arr[top];
		arr[top]=t;
		}
	}
struct Emp t=arr[high];
arr[high]=arr[top+1];
arr[top+1]=t;

return (top+1);
}
void InsertionSort(struct Emp arr[], int size)
{clock_t start,end;
start=clock();
for(int i=1;i<size;i++)
	{struct Emp ins=arr[i];
	int j=i-1;
	while(arr[j].id>ins.id && j>=0)
		{arr[j+1]=arr[j];j--;}
	arr[j+1]=ins;
	}
end=clock();
float seconds=(float)(end-start)/CLOCKS_PER_SEC;
printf("%f seconds taken for InsertionSort\n",seconds);
	//printEmp(arr,1000);
}
void iterQuickSort(struct Emp arr[],int S,int high,int low)
{clock_t start,end;
start=clock();
int *stack=(int *)malloc(sizeof(int)*(high-low+1));
int top_stack=0,p;
stack[top_stack]=low;
stack[++top_stack]=high;
while(top_stack>-1)
	{high=stack[top_stack--];
	low=stack[top_stack--];
	p=partition(arr,low,high);
	if(p-1-S-low>0)
		{stack[++top_stack]=low;
		stack[++top_stack]=p-1;
		}
	if(0<high-p-1-S)
		{stack[++top_stack]=p+1;
		stack[++top_stack]=high;
		}
	}

end=clock();
float seconds=(float)(end-start)/CLOCKS_PER_SEC;
printf("%f seconds taken for QuickSort\n",seconds);
//printEmp(arr,1000);
}
void testRun(struct Emp arr1[], int size)
{//float timers[2];
int i=2;
float secondsQ=1,secondsI=0;
while(secondsQ>=secondsI)
{
struct Emp *e1=(struct Emp *)malloc(size*sizeof(struct Emp));
struct Emp *e2=(struct Emp *)malloc(size*sizeof(struct Emp));
for(int j=0;j<size;j++)
	{strcpy(e2[j].name,arr1[j].name);
	e2[j].id=arr1[j].id;}
for(int j=0;j<size;j++)
	{strcpy(e1[j].name,arr1[j].name);
	e1[j].id=arr1[j].id;}
clock_t start,end;
start=clock();
iterQuickSort(e1,0,i-1,0);
end=clock();
secondsQ=(float)(end-start)/CLOCKS_PER_SEC;
start=clock();
InsertionSort(e2,i); 	
end=clock();
secondsI=(float)(end-start)/CLOCKS_PER_SEC;
i++;
free(e1);free(e2);
}
//while(
/*if(secondsI>secondsQ)
{printf("Insertion Sort is slower\nISTIME:%f\tQSTIME:%f\n",secondsI,secondsQ);}
else if(secondsI<secondsQ)
{printf("Quick Sort is slower\nISTIME:%f\tQSTIME:%f\n",secondsI,secondsQ);}
else
{printf("Equal time\nISTIME:%f\tQSTIME:%f\n",secondsI,secondsQ);}
*/
printf("ISTIME:%f\tQSTIME:%f\ni:%d\n",secondsI,secondsQ,i);
}
int main()
{int size=100000;
struct Emp *e1=(struct Emp *)malloc(size*sizeof(struct Emp));
struct Emp *e2=(struct Emp *)malloc(size*sizeof(struct Emp));
int i=0;
printf("Hello\n");
FILE *fptr;
fptr=fopen("100000","r");
if(fptr==NULL)
{printf("FILE CANNOT BE OPENED\n");
return EXIT_FAILURE;}

while(fscanf(fptr,"%10s %d",e1[i].name,&e1[i].id)!=-1&& i<size)
	{i++;}
	//printEmp(e,100000);
for(int j=0;j<size;j++)
	{strcpy(e2[j].name,e1[j].name);
	e2[j].id=e1[j].id;}
	
	printf("Hello\n");
fclose(fptr);
testRun(e1,size);
//printEmp(e,1000);
//printf("Executing Quicksort\n");
//iterQuickSort(e1,0,20,0);
//printf("Executing InsertionSort\n");
//InsertionSort(e2,20); 		
//printEmp(e,10);
}
