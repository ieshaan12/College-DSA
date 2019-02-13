#include<stdio.h>
#include<stdlib.h>
#include "ex2.h"

struct node {
int element;
struct node * next;
};

/*structure of a linked list / head. It stores the count of number of elements 
in the list and also a pointer link to the first node of the list. */

struct linkedList {
int count;
struct node * first;
};
void insertFirst(struct linkedList* head, int ele){
//create a node

struct node *link = (struct node*) myalloc(sizeof(struct node));
/*by this you are creating a node whose address is being stored in the link pointer.*/

link->next=head->first;
link->element=ele;
head->first=link;

head->count=head->count+1;
}
//display the list
void printList(struct linkedList * head){

struct node *temp= (struct node*) myalloc(sizeof(struct node));
temp=head->first;

while(temp!=NULL)
	{printf("%d\n",temp->element);
	temp=temp->next;
	}
}

int search(struct linkedList * head, int ele)
{struct node *temp= (struct node*) myalloc(sizeof(struct node));
temp=head->first;
int f=0;
while(temp!=NULL)
	{if(ele==temp->element)
		{f=1; break;}
	temp=temp->next;
	}
if(f==1){
return 1;}
return 0;
}

void createCycle( struct linkedList* list)
{srand(time(0));
int num=rand()%2;
int ele=rand();
if(num==1)
{struct node *temp= (struct node*) myalloc(sizeof(struct node));
temp=list->first;
int f=0;
while(temp!=NULL)
	{if(ele==temp->element)
		{f=1; break;}
	temp=temp->next;
	}
if(f==1){
struct node *temp2= (struct node*) myalloc(sizeof(struct node));
temp2=list->first;
while(temp2!=NULL)
	{if(temp2->next==NULL)
		{temp2->next=temp;break;}
		}
}}

}

int main()
{srand(time(0));
struct linkedList *list=(struct linkedList *)myalloc(sizeof(struct linkedList));
for( int i=0;i<1000000;i++)
{insertFirst(list,rand());
}
printList(list);
createCycle(list);

}
