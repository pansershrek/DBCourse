#include "hash.h"
//My methodes
int new_list(ht_list_ptr *luntik,void *page,const char *my_key,
    mytype hash_key,ht_list_ptr next,ht_list_ptr last) { 
    if ((luntik == NULL) || (page == NULL) || (my_key == NULL)) {
        return -1;
    }
    //create a new node for list
    (*luntik) = (ht_list_ptr)malloc(sizeof(ht_list));
    //i have been borned yet punk
    (*luntik)->page = page;
    strcpy((*luntik)->my_key,my_key);
    (*luntik)->hash_key=hash_key;
    (*luntik)->next=next;
    (*luntik)->last=last;
    return 0;
}
void del_list_one(ht_list_ptr in) {
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
void del_list(ht_list_ptr in) {
    if (in!=NULL) {
        if (in->next) {
            del_list_one(in->next);
        }
        del_list_one(in);
    }
}
int push_list(ht_list_ptr *top,ht_list_ptr in) {
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
/////////////////////////////////////
//functions for local test
void test_print(ht_list_ptr top) {
    if (!top) {
        return;
    }
    if (top->next) {
        test_print(top->next);
    }
    fprintf(stdout,"%d\n",top->test_flag);
}
int test_new_list(ht_list_ptr *luntik,char test_flag,ht_list_ptr next,ht_list_ptr last) { 
    //create a new node for list
    (*luntik) = (ht_list*)malloc(sizeof(ht_list));
    //i have been borned yet punk
    (*luntik)->test_flag=test_flag;
    (*luntik)->next=next;
    (*luntik)->last=last;
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