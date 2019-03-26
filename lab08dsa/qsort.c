#include "qsort.h"

/*
typedef struct keyStruct * KeyStruct;
struct keyStruct
{
	int* Keys;
	int keysSize;
};
*/
void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}
int* readData(char * fileName)
{

FILE * fptr=fopen(fileName,"r");

if(fptr==NULL)
	{printf("File can't be opened\n");
		return NULL;
	}
	
fscanf(fptr,"%d\n",&size);

int* ks=malloc(sizeof(int)*size);
printf("%d\n",size);

int i=0;
char a[10];

while(fscanf(fptr,"%[^\t]\t%d\n",a,(ks+i))!=-1)
	{printf("%d\n",*(ks+i));
	i++;
}
fclose(fptr);
return ks;
}
KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey){
KeyStruct ks=malloc(sizeof(KeyStruct));
ks->Keys=calloc(lsSize,sizeof(int));

int *arr=calloc(hiKey-loKey+1,sizeof(int));
for(int i=loKey,j=0;i<=hiKey;i++,j++)
	{arr[j]=i;}
for(int i=0;i<lsSize;i++)
	{if(Ls[i]>=loKey && Ls[i]<=hiKey)
		{int t=Ls[i]%(hiKey-loKey+1);
		arr[t]=-1;
		//printf("%d,",t);
		}
	}
int j=0;
for(int i=0;i<hiKey-loKey+1;i++)
	{//printf("%d,",arr[i]);
	if(arr[i]==-1)
		{//printf("%d\n",i+loKey);
		(ks->Keys)[j]=i+loKey+1;j++;
		}
	}
for(int i=0;i<j;i++)
	{printf("%d\n",(ks->Keys)[i]);
	}
	ks->keysSize=j;
return ks;
}
int part2Loc(int* Ls, int lo, int hi, int piv)
{
int i=lo-1;
int j=lo;
while(j<=high)
	{
	if(Ls[j]<=piv)
		{i++;
		int t=Ls[i];
		Ls[i]=:s[j];
		Ls[j]=t;
		}
	j++;
	}
return i+1;
}

