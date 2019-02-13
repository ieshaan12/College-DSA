#include<stdio.h>
#include "ex2.h"
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

int hare_tort(struct linkedList *list)
{struct node *hare=list->first;
 struct node *tort=list->first;
 int c=0;
 while(1)
{if(hare==NULL || tort==NULL || hare->next==NULL || (hare->next)->next==NULL)
{break;}	
hare=(hare->next)->next;
	tort=tort->next;
	printf("%d\n",tort->element);
if(hare->next==tort || hare==tort)
	{return 1;}			// 1 for cycle
if(hare==NULL || hare->next==NULL)
	{return 0;}			// 0 for linear

}
}
int main()
{struct linkedList *link = (struct linkedList*) myalloc(sizeof(struct linkedList));
for(int i=0;i<100;i++)
{insertFirst(link,i);}
printList(link);
int c=hare_tort(link);
if(c==0)
{printf("It is not a cycle\n");}
else if(c==1)
{printf("It is a cycle\n");}

}
