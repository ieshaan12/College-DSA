#include<stdio.h>
#include "functions.h"
#define size 249

int ind_last_free;
int ind_first_free;
typedef struct{
int head;
int list_num;
int count;
}list;
int arr[size];
list lists[50];
int list_no=1;
int create_free_list(){
arr[0]=-4;arr[1]=-2;
    for(int i=3;i<size;i+=3)
        {arr[i]=-4;arr[i-2]=i;}
    for(int i=2;i<size;i+=3)
        {arr[i]=-2;}
arr[247]=-3;
ind_last_free=246;
ind_first_free=0;
}
int create_list()
{int i,f=0;
    printf("The sequence number of the newly created list is: %d\n",list_no);
    for(i=0;i<size;i+=3)
        {if(arr[i+2]==-2 && arr[i]==-4)
            {//printf("List created");
		f=1;break;}
        }
    if(f==0)
    {printf("Failure: Memory not available");
    return 0;}
    else if(f==1)
    {   
        lists[list_no].head=i;
        lists[list_no].list_num=list_no;
	    lists[list_no].count=1;
    	printf("Enter number to be inserted in the newly created list -%d:",list_no);
    	insert_element(i);		//ind_first_free
    	arr[i+2]=-1;
    	arr[i+1]=-3;
    	list_no++;
	    printf("Success\n");
    }
/*
if(ind_first_free==-1)
 	{printf("Failure: Memory not available");return 0;}
lists[list_no].head=ind_first_free;
lists[list_no].list_num=list_no;
int temp=ind_first_free;
ind_first_free=arr[ind_first_free+1]
insert_element(temp);		//ind_first_free
arr[temp+2]=-1;
arr[temp+1]=-3;
list_no++;
*/
return 0;
}
int insert_in_list(){
    int lno,temp,i;
    int loc=0;//To check if memory is available or not
    printf("Please enter the list number: ");
    scanf("%d",&lno);
    if(!(lno<list_no))
        {printf("List not yet initialized\n");
        return 0;
        }
    else
        {temp=lists[lno].head;  //temp is the location of the head of the list
        while(arr[temp+1]!=-3)
        {temp=arr[temp+1];
        }
        //now (temp) is the index of the array of the last node in the list
        for(i=0;i<size;i+=3){
            if (arr[i]==-4 && arr[i+2]==-2)
                {//printf("entered");               
		loc=1;
                break;
                }
            }
        }
if(loc==0)
{printf("FAILURE: MEMORY NOT AVAILABLE");
    return 0;}
printf("Enter number to be inserted: ");
insert_element(i);
printf("Success\n");
arr[i+2]=temp; // stores prev as index of last element
arr[i+1]=-3;// this becomes the last element
arr[temp+1]=i; 
lists[lno].count++;
return 0;
}
int delete_from_list()
{int lno,temp,f=0,num;
printf("Enter List Number: ");
scanf("%d",&lno);
if(!(lno<list_no) && lno!=0)
	{printf("Invalid List Number\n");return 0;}
temp=lists[lno].head;
printf("Enter element to be removed: ");
scanf("%d",&num);
while(arr[temp+1]!=-3)
	{if(arr[temp]==num)
		{f=1;break;}
	temp=arr[temp+1];
	}
if(arr[temp]==num)
{f=1;}
if(f==0)
	{printf("Failure: Element not there\n");return 0;}
else 
	{//printf("Element to be removed: %d %d %d\n",num,temp,arr[temp]);
	lists[lno].count--;
	if(arr[temp+2]==-1)             //First element case
	    {int next=arr[temp+1];
	    arr[next+2]=-1;
	    lists[lno].head=next;
	    }
	else if(arr[temp+1]==-3)        //Last element case
	    {int prev=arr[temp+2];
	    arr[prev+1]=-3;
	    }
	else if(arr[temp+2]!=-1 && arr[temp+1]!=-3) //Middle element case
	    {int prev=arr[temp+2];
	    int next=arr[temp+1];
	    arr[prev+1]=next;
	    arr[next+2]=prev;
	    }
	//print_lists();
	for(int i=0;i<size;i+=3)
	{if(arr[i]==-4 && arr[i+1]==-3)
		{arr[i+1]=temp;break;
		}
	}
	arr[temp]=-4;arr[temp+2]=-2;arr[temp+1]=-3;
	//if(lists[lno].count==0)
		//{printf("List %d not part of the lists now",lno);}
	printf("Data successfully Removed\n");	
	}
	/*arr[ind_last_free+1]=temp;
	ind_last_free=temp;*/

}
int count_total()
{int count=0;
for(int i=0;i<size;i+=3)
	{if(arr[i+2]!=-2)
		{count++;}
	}
printf("Total number of nodes in all lists: %d\n",count);
return count;
}
int count_list()
{int lno;
printf("Enter List Number: ");
scanf("%d",&lno);
printf("Number of nodes in list(%d): %d\n",lno,lists[lno].count);
}
int insert_element(int pos){
    int num;//number to be inserted
    scanf("%d",&num);
    arr[pos]=num;
/*for(int i=0;i<size;i+=3)
    {
    if((arr[i+1])<=-1){
        scanf("%d",&num);
        arr[i]=num;
        }
    }*/
}
int print_lists()
{for(int i=1;i<list_no;i++){
    printf("List no: %d\n",i);
    printf("COUNT: %d\n",lists[i].count);
	int temp=lists[i].head;
	if (lists[i].count==0)
	{break;}
	else if(lists[i].count==1)
	{printf("Key\tNext\tPrev\n");
	printf("%d\tNIL\tNIL\n",arr[temp]);}
	else{
	    printf("Key\tNext\tPrev\n");
	    printf("%d\t%d\tNIL\n",arr[temp],arr[temp+1]);
	    temp=arr[temp+1];
        for(int j=1;j<lists[i].count-1;j++)
            {printf("%d\t%d\t%d\n",arr[temp],arr[temp+1],arr[temp+2]);
            temp=arr[temp+1];
            }
         printf("%d\tNIL\t%d\n",arr[temp],arr[temp+2]);
        }
        printf("\n");
    }

/*for(int i=1;i<list_no;i++)
	{printf("List no: %d\n",i);
	int temp=lists[i].head;
	printf("Key\tNext\tPrev\n");
	printf("%d\t%d\tNIL\n",arr[temp],arr[temp+1]);
	temp=arr[temp+1];
	while(arr[temp+1]!=-3)
		{printf("%d\t%d\t%d\n",arr[temp],arr[temp+1],arr[temp+2]);
		temp=arr[temp+1];}
	printf("%d\tNIL\t%d\n",arr[temp],arr[temp+2]);
	printf("\n");
	}*/
}
int defragmenter()
{int net=count_total();
//printf("Net=%d\n",net);
for(int i=0;i<3*net;i+=3)
	{if(arr[i]==-4 && arr[i+2]==-2)
		{printf("Entered first if condition for i=%d\n",i);
		for(int j=net*3;j<size;j+=3)
			{if(arr[j]!=-4 && arr[j+2]!=-2)
				{printf("Enterred first if condition for j=%d\n",j);				
				//gen case, assuming it has prev and next				
				int prev_ele=arr[j+2];
				int next_ele=arr[j+1];
				int next_free=arr[i+1];
				arr[i+1]=next_ele;//correct
				arr[i+2]=prev_ele;//correct
				arr[j+1]=next_free;//correct
				int prev_of_free;
				arr[i]=arr[j];//correct
				arr[j]=-4;//correct
				arr[j+2]=-3;//correct
				arr[next_ele+2]=i;
				arr[prev_ele+1]=i;
				for(int k=0;k<size;k++)
					{if(arr[k]==-4 && arr[k+2]==-2 && arr[k+1]==i)
						{prev_of_free=k;break;}
					}
				arr[prev_of_free+1]=j;
				//first element
				if(arr[i+2]==-1)
					{for(int t=0;t<list_no;t++)
						{if(lists[t].head==j)
						{lists[t].head=i;break;}
						}
					}
				break;
				}
			}
		}
	}
	printf("Success");			
}
int print_free()
{printf("Elements of free list are:\n");
printf("[");
for(int i=0;i<size;i+=3)
	{if(arr[i]==-4 && arr[i+2]==-2)
		{printf("%d,",i);
		}
	}
printf("]\n");
}
int print_arr()
{for(int i=0;i<size;i+=3)
printf("%d %d %d\n",arr[i],arr[i+1],arr[i+2]);
}
