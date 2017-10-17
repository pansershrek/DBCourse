#include "struct_for_hash.h"
//add list func

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