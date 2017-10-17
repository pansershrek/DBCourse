#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef long long mytype;
#define MAX_LEN 1024
//My 2 "class"
typedef struct List_for_Hash   //creat here my own list, with blackjack and wors
{   
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
typedef ht_list *ht_list_ptr;
typedef ht_node *ht_node_ptr;

//My methodes
int new_list(ht_list_ptr luntik,void *page,const char *my_key,
    mytype hash_key,ht_list_ptr next,ht_list_ptr last) { 
    if ((luntik == NULL) || (page == NULL) || (my_key == NULL)) {
        return -1;
    }
    //create a new node for list
    luntik = (ht_list_ptr)malloc(sizeof(ht_list));
    //i have been borned yet punk
    luntik->page = page;
    strcpy(luntik->my_key,my_key);
    luntik->hash_key=hash_key;
    luntik->next=next;
    luntik->last=last;
    return 0;
}
void del_list(ht_list_ptr in) {
    if (in != NULL) {
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++
        in->page=NULL;  //here we can delet page!!!!! dont forget
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++
        free(in->my_key);
        ht_list_ptr mid =in;
        if (mid->next) {
            mid->next->last = mid->last;
        }
        if (mid->last) {
            mid->last->next = mid->next;
        }
        free(in);
    }
}


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