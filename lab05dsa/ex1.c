#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
     clock_t start, end;
     double cpu_time_used;
     
typedef struct{
char Card_Number[20];
char Bank_Code[6];
char Expiry_Date[8];
char First_Name[30];
char Last_Name[30];
}Card;
void insertInOrder(Card *array,int n)
{int d;
	for (int i = 1 ; i<n; i++) {
   	 d = i;
 
    while ( d > 0 && strcmp(array[d-1].Card_Number,array[d].Card_Number)>0) {
	//printf("%s\n",array[d].Card_Number);
      Card t = array[d];
      array[d]   = array[d-1];
      array[d-1] = t;
      d--;
    }
  }
}
int main(){
	start = clock();
    FILE *file;
    file = fopen("10", "r");
	int n=10;
	if(file==NULL)
		{printf("Failure\n");
    	return EXIT_FAILURE;
		}
    int i=0;
    Card *c = (Card*)calloc(n,sizeof(Card));
    printf("Working\n");
    while (fscanf(file, "\"%[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^\"]%*c\n", c[i].Card_Number, c[i].Bank_Code, c[i].Expiry_Date, c[i].First_Name, c[i].Last_Name) != -1 ) {
        //printf("%s | %s | %s | %s | %s \n", c[i].Card_Number, c[i].Bank_Code, c[i].Expiry_Date, c[i].First_Name, c[i].Last_Name);
        i++;
	insertInOrder(c,i);
    }
    fclose(file);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	FILE *newFile=fopen("newFile","w+");
	fprintf(newFile,"Time taken:%lf\n",cpu_time_used);
	fclose(newFile);
	//insertInOrder(c,n);
	//printf("\nSorted\n\n");
for(int j=0;j<n;j++)
		{printf("%s | %s | %s | %s | %s \n", c[j].Card_Number, c[j].Bank_Code, c[j].Expiry_Date, c[j].First_Name, c[j].Last_Name);}
	
    return 0;
}
