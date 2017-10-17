#include "struct_for_hash.h"
//add list func
extern int new_list(ht_list_ptr *luntik,void *page,const char *my_key,
    mytype hash_key,ht_list_ptr next,ht_list_ptr last);
extern void del_list_one(ht_list_ptr in);
extern void del_list(ht_list_ptr in);
extern int push_list(ht_list_ptr *top,ht_list_ptr in);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//test functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
extern void test_print(ht_list_ptr top);
extern int test_new_list(ht_list_ptr *luntik,char test_flag,ht_list_ptr next,ht_list_ptr last);
extern void test_del_list_one(ht_list_ptr in);
extern void test_del_list(ht_list_ptr in);
extern int test_push_list(ht_list_ptr *top,ht_list_ptr in);

//////////////////////////////////////
extern mytype hash();
int 
main(void) {
    /*char test[1000];
    memset(test,'\0',sizeof(test));
    scanf("%s",test);
    printf("%d\n",(int)('l'));
    printf("%lld\n",hash(test));
    */
    ht_list_ptr top =NULL;
    for (int i=0;i<10;i++) {
        ht_list_ptr mid;
        test_new_list(&mid,i,NULL,NULL);
        //test_print(mid);
        test_push_list(&top,mid);
    }
    test_print(top);
    test_del_list(top);
    return 0;
}