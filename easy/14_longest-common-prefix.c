char* longestCommonPrefix(char** strs, int strsSize) {
    int flag = 0, i;
    for (i=0; i<strlen(strs[0]); i++){
        for (int j=1; j<strsSize; j++){
            if (strs[j][i] != strs[0][i]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            char* output = malloc(sizeof(char)*(i+1));
            strncpy(output, strs[0], i);
            output[i] = '\0'; //手動加上終止符
            return output;
        }
    }
    char* output = malloc(sizeof(char)*(strlen(strs[0])+1));
    strncpy(output, strs[0], i);
    output[i] = '\0'; //手動加上終止符
    return output;
}
