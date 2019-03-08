#include<time.h>
#include<stdlib.h>
#include<stdio.h>
clock_t start,end;
int power(int a,int b)
{int mul=1;
for(int i=b;i>0;i--)
{mul=mul*a;}
return mul;
}
void initArr(int arr[],int size,int val){
for(int i=0;i<size;i++){
arr[i]=val;
}
}
void printArr(int arr[],int size){
for(int i=0;i<size;i++){
printf("%d,",arr[i]);
}
printf("\n");
}
int main()
{start=clock();
int size=10,dig=10;
int arr[size],max=2; //max is number of maximum digits in the number
int histogram[dig],final[size];
initArr(histogram,dig,0);
initArr(final,size,-1);
srand(time(0));
for(int i=0;i<size;i++)
{arr[i]=rand()%(size*10);
}
printArr(arr,size);
for(int k=0;k<max;k++)
{int temp[size];
initArr(histogram,dig,0);
for(int i=0;i<size;i++)
{temp[i]=(arr[i]/power(10,k))%10;
} //be sure to switch arr[i] and not temp [i]
for(int i=0;i<size;i++)
{histogram[temp[i]]++;
}
printf("Histogram, without adding %d\n",k);
printArr(histogram,dig);
for(int i=1;i<size;i++){
histogram[i]=histogram[i]+histogram[i-1];
}
printf("Histogram, %d\n",k);
printArr(histogram,dig);
for(int j=size-1;j>=0;j--)
{final[histogram[temp[j]]-1]=arr[j];
histogram[temp[j]]--;
}
printArr(histogram,dig);
{for(int i=0;i<size;i++){
arr[i]=final[i];}
}
}
printArr(arr,size);
end=clock();
float time_taken=(float)(end-start)/CLOCKS_PER_SEC;
printf("Time Taken:%f\n",time_taken);
}