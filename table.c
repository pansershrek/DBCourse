#include "struct_for_hash.h"
int new_node(ht_node_ptr *in) {
    //create new hash table
    (*in) = (ht_node*)malloc(sizeof(ht_node));
    if (!(*in)) {
        return -1;
    }
    return 0;
}
void insert_list_in_hash(ht_node_ptr in, ht_list_ptr top) {
    //insert list in hash
    top->hash_key = hash(top->my_key,in->dep);
    in->len_of_list[top->hash_key]++;
    push_list(in->top[top->hash_key],top);
}
void remake_hash(ht_node_ptr in, mytype index) {
    if (in->len_of_list[index] == MAX_HASH_DEP) {//if == then it is flag that make new hash, if > that it is hash
        ht_node_ptr new_hash;
        new_node((&new_hash));
        new_hash->dep=in->dep+1;
        ht_list_ptr ttop = new_hash->top[index];
        while (ttop != NULL) {
            ht_list_ptr mid = ttop;
            ttop = ttop->next;
            ttop->last = NULL;//here is costili, it can be new method, but i am busy now
            mid->next = NULL;
            insert_list_in_hash(new_hash,mid);
        }
        in->len_of_list[index]++;
        in->top[index] = new_hash;
    } 
}
ht_list_ptr search_in_hash(ht_node_ptr in, const char *key) {
    if (!key) {
        return NULL;
    }
    mytype mid_key = hash(key,in->dep);
    while (1) {
        if (in == NULL) {
            return NULL; 
        } else if (in->len_of_list[mid_key]<MAX_HASH_DEP) {
            return search_in_list(in->top[mid_key],key);
        } else {
            in = in->top[mid_key];
        }
    }
}
int erase_from_hash(ht_node_ptr in,const char *key) {
    if (!key) {
        return 0;
    }
    ht_list_ptr result = search_in_hash(in,key);
    if (!result) {
        return 0;
    } else {
        del_list_one(result);
    }
}
void insert_in_hash(ht_node_ptr in,ht_list_ptr new_list) {
    mytype mid_key = hash(new_list->my_key,in->dep);
    while (in->len_of_list[mid_key]>MAX_HASH_DEP) {
        in=in->top[mid_key];
        mid_key = hash(new_list->my_key,in->dep);
    }
    in->len_of_list[mid_key]++;
    push_list(in->top[mid_key],new_list);
    remake_hash(in,mid_key);
    return;
}