#include "struct_for_hash.h"
//My methodes
int new_list(ht_list_ptr *in,void *page,const char *my_key,
    mytype hash_key,ht_list_ptr next,ht_list_ptr last) { 
    if ((page == NULL) || (my_key == NULL)) {
        return -1;
    }
    //create a new node for list
    (*in) = (ht_list_ptr)malloc(sizeof(ht_list));
    if (!(*in)) {
        return -1;
    }   
    //i have been borned yet punk
    (*in)->page = page;
    strcpy((*in)->my_key,my_key);
    (*in)->hash_key=hash_key;
    (*in)->next=next;
    (*in)->last=last;
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
ht_list_ptr search_in_list(ht_list_ptr top,const char *key) {
    if (!key) {
        return NULL;
    }
    while (top) {
        if (strcmp(top->my_key,key) == 0) {
            return top;
        } else {
            top = top->next;
        }
    }
    return NULL; 
}
