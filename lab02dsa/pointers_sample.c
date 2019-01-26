/* Pointers_Sample.c */
#include <stdio.h>
int main () {
int  var = 20;   /* actual variable declaration */
int  *ip;        /* pointer variable declaration */
ip = &var;  /* store address of var in pointer variable*/

//IMPORTANT ADDITION: Understand what does %u, %x and %p, their differences and similarities
//%x is hexadecimal and %u is a decimal value

printf("Address of var variable: %p %x %u\n", &var, &var, &var  );

/* address stored in pointer variable */
printf("Address stored in ip variable: %p %x %u\n", ip, ip, ip );

/* access the value using the pointer */
printf("Value of *ip variable: %d\n", *ip );
return 0;
}
