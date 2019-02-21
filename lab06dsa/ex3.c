#include<stdio.h>
#include<stdlib.h>
typedef struct{
char Name[10];
float cgpa;
}Element;
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void mergeSort(Element arr[], int l, int r) 
{//printf("inMegesort\n"); 	
Element *arr1=(Element *)calloc(r-l,sizeof(Element));
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
void mergeFiles()
{
FILE *output=fopen("Out","w");
Element e1,e2;
FILE *f1=fopen("1.txt","r+");
FILE *f2=fopen("0.txt","r+");
int i=0;
fscanf(f1,"%10s,%f\n",e1.Name,&e1.cgpa);
fscanf(f2,"%10s,%f\n",e2.Name,&e2.cgpa);
while(i<10240){
	if(e1.cgpa<e2.cgpa)
		{fprintf(output,"%s\t%f\n",e1.Name,e1.cgpa);
		fscanf(f1,"%10s,%f\n",e1.Name,&e1.cgpa);
		}
	else
		{fprintf(output,"%s\t%f\n",e2.Name,e2.cgpa);
		fscanf(f2,"%10s,%f\n",e2.Name,&e2.cgpa);
		}
	i++;
	}
	fclose(f1);
	fclose(f2);
	fclose(output);
}
int main(){
Element arr[5120];
FILE *fptr1=fopen("10240.txt","r+");
//FILE *writer=fopen("Sorted","w");
if(fptr1==NULL)
{	printf("Can't open file\n");
    return EXIT_FAILURE;
}
int i=0,f=0;
for(int i=0;i<2;i++)
	{int j;
	for(j=0;j<5120;j++)
		{f=fscanf(fptr1,"%10s,%f\n",arr[j].Name,&arr[j].cgpa);
		if(f==-1){break;}
		}
		if(f==-1){break;}
	mergeSort(arr,0,5119);
	char a[10];
	sprintf(a,"%d.txt",i);
	//printf("%s\n",a);
	FILE *writer=fopen(a,"w");
	for(int k=0;k<5120;k++)
		{fprintf(writer,"%s,%f\n",arr[k].Name,arr[k].cgpa);}
	fclose(writer); 
	}
	fclose(fptr1);
	mergeFiles();
}
