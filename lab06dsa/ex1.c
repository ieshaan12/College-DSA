#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct{
char Name[10];
float cgpa;
}Element;

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
/*
void MERGE(Element arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    
    Element L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i].cgpa <= R[j].cgpa) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} */

void mergeSort(Element arr[], int l, int r) 
{//printf("inMegesort\n"); 	
Element *arr1=(Element *)calloc(1024,sizeof(Element));
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  		
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  		//printf("%d\t%d\n",l,r); 
        merge(arr+l,m-l+1, arr+m+1,r-m, arr1); 
    }
    else if(l==r)
    {return;}
    for(int i=l;i<=r;i++)
    {arr[i]=arr1[i-l];
    } 
   
} 

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[])
{
int i=0,j=0,k=0;
while(i<sz1 && j<sz2)
	{if(Ls1[i].cgpa<Ls2[j].cgpa)
		{Ls[k]=Ls1[i];
		i++;k++;}
	else
		{Ls[k]=Ls2[j];
		j++;k++;
		}
	}
	while(i<sz1)
		{Ls[k]=Ls1[i];
		k++;i++;}
	while(j<sz2)
		{Ls[k]=Ls2[j];
		j++;k++;
		}
//return Ls;
}
Element *sortArray(Element arr[],int size)
{for(int i=0;i<size;i++)
	{for(int j=0;j<size;j++)
		{if(arr[i].cgpa>arr[j].cgpa)
			{Element t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
			}
		}
	}
return arr;
}
void print(Element arr[],int size)
{for(int i=0;i<size;i++)
	{printf("%s\t%f\n",arr[i].Name,arr[i].cgpa);}
}
int main()
{
Element arr[1024];
FILE *fptr1=fopen("1024.txt","r+");
if(fptr1==NULL)
{	printf("Can't open file\n");
    return EXIT_FAILURE;
}
int i=0;
while(fscanf(fptr1,"%10s,%f\n",arr[i].Name,&arr[i].cgpa)!=-1)	
	{//printf("%s\t%f\n",arr[i].Name,arr[i].cgpa);
	i++;}
fclose(fptr1);

Element array[10240];
FILE *fptr2=fopen("10240.txt","r+");
if(fptr2==NULL)
{	printf("Can't open file\n");
    return EXIT_FAILURE;
}
int j=0;
while(fscanf(fptr2,"%10s,%f\n",array[j].Name,&array[j].cgpa)!=-1)	
	{//printf("%s\t%f\n",array[j].Name,array[j].cgpa);
	j++;}
fclose(fptr2);

Element *arr1,*arr2,*finalArray;
finalArray=(Element *)calloc(11264,sizeof(Element));
//printf("Hello\n");
mergeSort(arr,0,1023);
//printf("Hello\n");
print(arr,1023);
//printf("Hello\n");  
/*arr1=sortArray(arr,1024);
arr2=sortArray(array,10240);
finalArray=merge(arr,1024,array,10240,finalArray);
//mergeSort(finalArray,0,11263);
print(finalArray,11264);*/

}
	
