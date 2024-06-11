char* countAndSay(int n) {
    if (n == 1) {
       char* out = (char*)malloc(2);
       out[0] = '1';
       out[1] = '\0';
       return out;
    }
    char* a = countAndSay(n - 1);
    char* out = (char*)malloc(2 * strlen(a) + 1);
    int i = 0, count = 0, j = 0;
    while (a[i] != '\0') {
        if (i == 0 || a[i] == a[i-1]) {
            ++count;
        }
        else {
            out[j] = count + '0';
            ++j;
            count = 1;
            out[j] = a[i-1];
            ++j;
        }
        ++i;
    }
    out[j] = count + '0';
    ++j;
    out[j] = a[i-1];
    ++j;
    out[j] = '\0';
    free(a);
    return out;
}
