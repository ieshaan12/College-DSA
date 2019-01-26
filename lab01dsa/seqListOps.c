/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{int t,i;
for( i=st[sl.head].next;st[i].next!=-1;i=st[i].next)
{ORDER O=compare(j,st[i].ele);
if(O==GREATER)
{break;}
}
t=nextfreeloc++;
st[t].ele=j;
st[t].next=st[i].next;
st[i].next=t;
sl.size++;
return sl;

 }
  
void insertelements (JobList list , SeqList s[])
{
for(int i=0;i<MAX;i++)
{if(list[i].pri==0)
	{s[0]=insert(list[i],s[0]);
	}
else if(list[i].pri==1)
	{s[1]=insert(list[i],s[1]);
	}
else if(list[i].pri==2)
	{s[1]=insert(list[i],s[2]);
	}
}

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{int t=0,i,j;
for(i=2;i>=0;i--)
{	for( j=st[s[i].head].next;st[j].next!=-1;j=st[j].next)
		{ele[t]=st[j].ele;
		t++;
		}
	ele[t]=st[j].ele;
t++;
}
}

void printlist(SeqList sl)
{
for(int i=st[sl.head].next;st[i].next!=-1;i=st[i].next)
{printJob(st[i].ele);}

}

void printJobList(JobList list, int size)
{
for(int i=0;i<size;i++)
{printJob(list[i]);}
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
