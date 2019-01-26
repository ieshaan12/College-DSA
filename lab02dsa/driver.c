/* driver.c */
#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
int main(int argc, char *argv[]){

// Create a filepointer and open the file read as command line argument.
FILE * fileptr = fopen(argv[1], "r");

// Declare a pointer to a linked list (head) and allocate memory to it.
struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));

// In a loop read the file and insert elements into the linkedList.
while (!feof(fileptr)){
	// read the next element and store into the temp variable.
	int temp;
	fscanf(fileptr, "%d ", &temp);
	// insert temp into the linked list.
	insertFirst(head,temp);
	}
// close the file pointer
fclose(fileptr);

printf("Printing list\n");
printList(head);

deleteFirst(head);

printf("Printing list after deletion\n");
printList(head);

if(search(head,7)==1)
printf("Number found\n");
else
printf("Not found\n");

delete(head,3);
printList(head);

}
