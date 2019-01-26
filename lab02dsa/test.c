#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
//printf("\n%d\n%d\n",atoi(argv[1]),argc);
for(int i=0;i<argc;i++)
	{printf("%s ",argv[i]);
	int x=atoi(argv[i]);
	if (x!=0)
		{
		printf("%d\n",x);
		}
	else
		{printf("Not a number\n");}
	}

	
//printf("Hello World !!!!");
}
