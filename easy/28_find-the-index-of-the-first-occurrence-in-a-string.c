int strStr(char* haystack, char* needle) {
    //Knuth-Morris-Pratt Algorithm
    int l_h = strlen(haystack), l_n = strlen(needle);
    // 如果 needle 是空字符串，返回 0
    if (l_n == 0) return 0;

    //次長共同前後綴（Longest Proper Prefix Which Is Also Suffix)
    int arr[l_n],i = 1, j = 0;
    arr[0] = 0;
    while (i<l_n) {
        if (needle[i] == needle[j]) {
            arr[i] = ++j; //j=j+1; arr[i] = j;
            ++i;
        }
        else {
            if (j == 0) {
                arr[i] = 0;
                ++i;
            }
            else j = arr[j-1];
        }
    }

    int end = l_h - l_n;
    i = 0, j = 0;
    while (true) {
        if (haystack[i] == needle[j]) {
            if (++j == l_n) return i-j+1; //先j=j+1;
            else {
                ++i;
            }
        }
        else {
            if (j == 0) {
                if (i > end) break;
                ++i;
            }
            else j = arr[j-1];
        }
    }
    //needle is not part of haystack
    return -1;
}
