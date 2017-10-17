#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef long long mytype;
#define MAX_LEN 1024
#define MAX_HASH_DEP 1024
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
    // if len_of_list[index]>MAX_LEN then top[index] is a ptr on new hash_table, else it is ptr on list
    // dont forget mix hash after create new child table!!!!
    int dep;
    mytype  len_of_list[MAX_HASH_DEP]; //here i save the length of each list    
    void  *top[MAX_LEN];  //here is my ptr on list or on hash table
} ht_node;
//let's make live easy!!! or hard??!!
typedef ht_list *ht_list_ptr;
typedef ht_node *ht_node_ptr;
//+++++++++++++++++++++++++++++++++++++++++++
//func whith list
//+++++++++++++++++++++++++++++++++++++++++++
extern int new_list(ht_list_ptr *luntik,void *page,const char *my_key,
    mytype hash_key,ht_list_ptr next,ht_list_ptr last);
extern void del_list_one(ht_list_ptr in);
extern void del_list(ht_list_ptr in);
extern int push_list(ht_list_ptr *top,ht_list_ptr in);
extern ht_list_ptr search_in_list(ht_list_ptr top,const char *key);
//+++++++++++++++++++++++++++++++++++++++++++
//func with hash table
//+++++++++++++++++++++++++++++++++++++++++++
extern int new_node(ht_node_ptr *in);
extern void insert_list_in_hash(ht_node_ptr in, ht_list_ptr top) ;
extern void remake_hash(ht_node_ptr in, mytype index);
extern ht_list_ptr search_in_hash(ht_node_ptr in, const char *key);
extern int erase_from_hash(ht_node_ptr in,const char *key);
extern void insert_in_hash(ht_node_ptr in,ht_list_ptr new_list);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//test functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
extern void test_print(ht_list_ptr top);
extern int test_new_list(ht_list_ptr *luntik,char test_flag,ht_list_ptr next,ht_list_ptr last);
extern void test_del_list_one(ht_list_ptr in);
extern void test_del_list(ht_list_ptr in);
extern int test_push_list(ht_list_ptr *top,ht_list_ptr in);

//////////////////////////////////////
extern mytype next_hash (const char *key);
extern mytype hash();