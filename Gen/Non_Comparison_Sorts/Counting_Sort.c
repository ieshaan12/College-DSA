#include<time.h>
#include<stdlib.h>
#include<stdio.h>
clock_t start,end;
void printArr(int arr[],int size){
for(int i=0;i<size;i++){
	printf("%d,",arr[i]);
	}
printf("\n");
}
void initArr(int arr[],int size,int val){
for(int i=0;i<size;i++){
	arr[i]=val;
	}
}
int main()
{start=clock();
int size=8,dig=6;
int arr[]={2,5,3,0,2,3,0,3};int final[size];
//Let us consider digits to be among 0 to 5
int histogram[dig];
initArr(histogram,dig,0);
initArr(final,size,-1);
srand(time(0));
for(int i=0;i<size;i++)
	{//arr[i]=rand()%6;
	histogram[arr[i]]++;
	}
printArr(arr,size);
for(int i=1;i<size;i++){
	histogram[i]=histogram[i]+histogram[i-1];
	}
for(int j=size-1;j>=0;j--)
	{final[histogram[arr[j]]-1]=arr[j];
	histogram[arr[j]]--;
	/*printf("Result\n");
	printArr(final,size);
	printf("Histogram\n");
	printArr(histogram,size);*/
	}
printArr(final,size);
end=clock();
float time_taken=(float)(end-start)/CLOCKS_PER_SEC;
printf("Time Taken:%f\n",time_taken);
}
