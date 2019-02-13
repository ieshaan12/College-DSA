#include<stdio.h>
int hare_tort(struct linkedList *list)
{struct Node *hare=(struct Node *)myalloc(sizeof(struct Node));
 struct Node *tort=(struct Node *)myalloc(sizeof(struct Node));
 int c=0;
 while(true)
{if(hare->element==tort->element && hare->next==tort->next){
	return 1;}			// 1 for cycle
if((hare->next)->next==NULL || tort->next=NULL)
	{return 0;}			// 0 for linear
hare=(hare->next)->next;
tort=tort->next;
}
}
