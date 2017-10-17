#include <stdio.h>
#include <string.h>
#include <stdlib.o>
typedef long long mytype;
#define MAX_LEN=1024;
typedef struct List_for_Hash_Table   //creat here my own list, with blackjack and wors
{   
    void *page;
    char my_key[MAX_LEN_KEY];
    mytype hash_key;
    struct List_for_Hash_Table *next,*last; // i want to go next, or last, or next, i did't decide
} *ht_list;
typedef struct Hash_Table  //create here hast table
{ 
    // if len_of_list[index]==MAX_LEN then top[index] is a ptr on new hash_table, else it is ptr on list
    mytype  len_of_list[MAX_LEN]; //here i save the length of each list    
    void  *top[MAX_LEN];  //here is my ptr on list or on hash table
    
} *ht_node;
extern mytype hash();
int 
main(void) {
    char test[1000];
    memset(test,'\0',sizeof(test));
    scanf("%s",test);
    printf("%d\n",(int)('l'));
    printf("%lld\n",hash(test));
    return 0;
}