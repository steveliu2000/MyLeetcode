int lengthOfLongestSubstring(char* s) {
    int l = strlen(s), n=1;
    if (l == 0) return 0;
    int i=0, j=1, k;
    while(true){
        if (j>=l) break;
        for (k=i;k<j;k++){
            if (s[k]==s[j]){
                i = k+1;
                break;
            }  
        }
        j++;
        n = (n>j-i) ? n:j-i;
    }
    return n;
}
