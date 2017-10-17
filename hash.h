#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef long long mytype;
#define MAX_LEN 1024
//My 2 "class"
typedef struct List_for_Hash   //creat here my own list, with blackjack and wors
{   
    //++++++++++++++++++++++
    char test_flag;// only for local test!!!dont forget
    //++++++++++++++++++++++
    void *page;
    char my_key[MAX_LEN];
    mytype hash_key;
    struct List_for_Hash *next,*last; // i want to go next, or last, or next, i did't decide
} ht_list;

typedef struct Hash_Table  //create here hast table
{ 
    // if len_of_list[index]==MAX_LEN then top[index] is a ptr on new hash_table, else it is ptr on list
    // dont forget mix hash after create new child table!!!!
    mytype  len_of_list[MAX_LEN]; //here i save the length of each list    
    void  *top[MAX_LEN];  //here is my ptr on list or on hash table
} ht_node;
//let's make live easy!!! or hard??!!
typedef ht_list *ht_list_ptr;
typedef ht_node *ht_node_ptr;