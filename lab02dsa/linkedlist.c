/* linkedlist.c */
#include "linkedlist.h"
void insertFirst(struct linkedList* head, int ele){
//create a node

struct node *link = (struct node*) malloc(sizeof(struct node));
/*by this you are creating a node whose address is being stored in the link pointer.*/

link->next=head->first;
link->element=ele;
head->first=link;

head->count=head->count+1;
}
//delete first item
struct node* deleteFirst(struct linkedList * head){
// exercise to implement this operation.

struct node *temp= (struct node*) malloc(sizeof(struct node));

temp=head->first;
temp=temp->next;
head->first=temp;
head->count=head->count-1;
}

//display the list
void printList(struct linkedList * head){

struct node *temp= (struct node*) malloc(sizeof(struct node));
temp=head->first;

while(temp!=NULL)
	{printf("%d\n",temp->element);
	temp=temp->next;
	}
}
int search(struct linkedList * head, int ele)
{struct node *temp= (struct node*) malloc(sizeof(struct node));
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
struct node * delete(struct linkedList * head,int ele)
{struct node *temp= (struct node*) malloc(sizeof(struct node));
temp=head->first;
int f=0;
while(temp!=NULL)
	{if(ele==temp->element)
		{f=1; break;}
	temp=temp->next;
	}
if(f==1)
{printf("Element found\n");
return deleteFirst(head);}
printf("Element not found\n");
return NULL;
}





