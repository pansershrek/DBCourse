#include "struct_for_hash.h"

int test_new_list(ht_list_ptr *in,char test_flag,ht_list_ptr next,ht_list_ptr last) { 
    //create a new node for list
    (*in) = (ht_list*)malloc(sizeof(ht_list));
    if (!(*in)) {
        return -1;
    }
    //i have been borned yet punk
    (*in)->test_flag=test_flag;
    (*in)->next=next;
    (*in)->last=last;
    return 0;
}
void test_del_list_one(ht_list_ptr in) {
    if (in != NULL) {
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
void test_del_list(ht_list_ptr in) {
    if (in!=NULL) {
        if (in->next) {
            test_del_list(in->next);
        }
        test_del_list_one(in);
    }
}
int test_push_list(ht_list_ptr *top,ht_list_ptr in) {
    //push in list
    //+++++++++++++++++++++++
    //cheak for errores
    //+++++++++++++++++++++++
    if (!(*top)) {
        *top=in;
        return 0;
    }
    if (!(top) || !(in))  
    return -1;
    in->next=*top;
    (*top)->last=in;
    *top=in;
    return 0;
}