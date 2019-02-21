#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include "ex2.h"
struct node {
	int element;
	struct node * next;
};
struct linkedList {
int count;
struct node * first;
};
void insertFirst(struct linkedList* head, int ele){
//create a node

struct node *link = (struct node*) malloc(sizeof(struct node));
/*by this you are creating a node whose address is being stored in the link pointer.*/

link->next=head->first;
link->element=ele;
head->first=link;

head->count=head->count+1;
}
struct linkedList * createList(int N)
{
struct linkedList *ls=(struct linkedList *)malloc(sizeof(struct linkedList));
FILE * fptr=fopen("newFile","w+");
for(int i=0;i<N;i++)
	{int temp=rand()%100;
	insertFirst(ls,temp);
	fprintf(fptr,"%d\n",temp);
	}
fclose(fptr);
return ls;
}
struct linkedList * createCycle(struct linkedList *ls)
{struct node *firstNode= (struct node*) malloc(sizeof(struct node));
firstNode=ls->first;
srand(time(0));
int choice=rand()%2;
printf("%d\n",choice);
int f=0;
if(choice == 1)
	{int t=rand()%100;
	while((firstNode->next)->next!=NULL)
		{firstNode=firstNode->next;}
	struct node *temp= (struct node*) malloc(sizeof(struct node));
	while(temp!=NULL)
	{if(t==temp->element)
		{f=1; break;}
	temp=temp->next;
	}
	if(f==0)
		{return ls;}
	else if(f==1)
	{firstNode->next=temp;
	return ls;
	}
	}
return ls;
}
int main()
{
struct linkedList *list=createList(20);
list=createCycle(list);
}
