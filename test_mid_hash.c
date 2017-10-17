#include "struct_for_hash.h"

mytype hash (const char *key,int dep) { // dep if parametr for change const in hash f
    mytype mid = 0, p = 57, m = 1031;
    while (*key) {
        mid = (mid + p * ((mytype)(*key))) % m;
        key++;
    }
    return mid;
}
mytype next_hash (const char *key) {
    mytype mid = 0, p = 73, m = 3041;
    while (*key) {
        mid = (mid + p * ((mytype)(*key))) % m;
        key++;
    }
    return mid;
}

