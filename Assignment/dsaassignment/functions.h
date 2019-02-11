#include <stdio.h>
#include <stdlib.h>


// -2: prev=-2 and next -2 and key=0, Indicates memory is free
// -3: Defined as next of a node is free for now, i.e. this is the last element currently
// -1: Indicates the prev of this node is -1 i.e. this is the first element of the list
// For free list key:-4,next:[addr],prev is left as -2
int create_free_list();
int create_list();
int insert_element();
int insert_in_list();
int delete_from_list();
int count_total();
int count_list();
int print_free();
int print_lists();
int defragmenter();
int print_arr();

