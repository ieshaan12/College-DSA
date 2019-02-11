#include<stdio.h>
#include "functions.h"

int option_menu()
{
    int n;
        printf("Select an option:\n");
        printf("1. Create a new list\n");
        printf("2. Insert a new element in a given list in sorted order\n");
        printf("3. Delete an element from a given list\n");
        printf("4. Count total elements excluding free list\n");
        printf("5. Count total elements of a list\n");
        printf("6. Display all lists\n");
        printf("7. Display free list\n");
        printf("8. Perform defragmentation\n");
        printf("9. Press 0 to exit\n");
    scanf("%d",&n);
switch(n){
    case 0:break;
    case 1:
        create_list();      //Creates new list
        option_menu(); break;
    case 2:
        insert_in_list();
        option_menu(); break;
    case 3:delete_from_list();
        option_menu(); break;
    case 4:
	count_total();
        option_menu(); break;
    case 5:
	count_list();
        option_menu(); break;
    case 6:
	print_lists();
        option_menu(); break;
    case 7:
	print_free();
        option_menu(); break;
    case 8:defragmenter();
        option_menu(); break;
    case 9://print_arr();
        option_menu(); break;
    default:printf("Wrong option\n Enter again\n");
        option_menu();break;
}
return 0;
}
int main()
{create_free_list();
option_menu();

    //option_menu();
}
