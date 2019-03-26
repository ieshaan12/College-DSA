#include "List.h"
/*typedef struct student * Student;
struct student
{
	char * name;
	float marks;
};

typedef struct node * Node;
struct node
{
	Student record;
	Node next;
};


typedef struct list * List;
struct list
{
	int count;
	Node first;
	Node last;
};*/
List createList(Student studArray, int arraySize)
{

List l=(List)myalloc(sizeof(struct list));
//printf("Student Arr,%f %s",studArray->marks,studArray->name);
//printf("Student Arr,%f %s",(studArray+1)->marks,(studArray+1)->name);


for(int i=0;i<arraySize;i++)

	{Node rec=(Node)myalloc(sizeof(struct node));
		rec->record=(studArray+i);
		rec->next=NULL;
		insertInOrder(l, rec);
	/*if(i!=0)
		{
		(l->last)->next=rec;	//(l->last)->next=rec;			
		l->last=rec;				//l->last=n;
		(l->count)++;
		}
	else{
		/*l->first=rec;
		l->last=rec;
		(l->count)++;
		}*/
	}

return l;
}

void * myalloc(int size)
{
void *ptr=malloc(size+sizeof(int));
*(int *)ptr=size;
globalCounter=globalCounter+size;
return ptr+sizeof(int);
}

void myfree(void* ptr)
{int size_del=*(int *)(ptr-sizeof(int));
//printf("%d\n",size_del);
globalCounter=globalCounter-size_del;
ptr=ptr-sizeof(int);
free(ptr);
}

void insertInOrder(List list, Node newNode){
if(list->count==0)
	{list->first=newNode;
		list->last=newNode;
		(list->count)++;
	}
else{	Node n=(Node)myalloc(sizeof(struct node));
		n=list->first;
		while(n!=(list->last)->next && (n->record)->marks < (newNode->record)->marks)
			{n=n->next;
			}
		newNode->next=n;
		n=newNode;
		while((n->next)!=NULL)
			n=n->next;
		list->last=n;
		(list->count)++;
		/*(list->last)->next=newNode;	//(l->last)->next=rec;			
		list->last=newNode;				//l->last=n;
		(list->count)++;
		*/
	}
}
/*
List insertionSort(List list){
	insertInOrder(list);

}*/



