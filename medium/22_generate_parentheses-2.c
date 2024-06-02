void generateParenthesisHelper(int n, int open, int close, char* current, int pos, char** result, int* returnSize) {
    if (pos == 2 * n) {
        current[pos] = '\0';  // 結束字元
        result[*returnSize] = (char*)malloc(sizeof(char) * (2 * n + 1));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        generateParenthesisHelper(n, open + 1, close, current, pos + 1, result, returnSize);
    }
    if (close < open) {
        current[pos] = ')';
        generateParenthesisHelper(n, open, close + 1, current, pos + 1, result, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;
    int maxSize = pow(2, 2 * n);  // 最大可能的組合數量
    char** result = (char**)malloc(sizeof(char*) * maxSize);
    char* current = (char*)malloc(sizeof(char) * (2 * n + 1));

    generateParenthesisHelper(n, 0, 0, current, 0, result, returnSize);

    free(current);

    return result;
}
