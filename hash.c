typedef long long mytype;
mytype 
hash (const char *key) {
    mytype mid = 0, p = 57, m = 1031;
    while (*key) {
        mid = (mid + p * ((mytype)(*key))) % m;
        key++;
    }
    return mid;
}