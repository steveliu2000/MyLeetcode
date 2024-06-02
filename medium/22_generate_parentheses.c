/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    // *returnSize = 1/(n+1) * C(2n, n)
    *returnSize = 1;
    for (int i = n + 2; i <= 2 * n; ++i) (*returnSize) *= i;
    for (int i = 2; i <= n; ++i) (*returnSize) /= i;

    char** out = (char**)malloc(sizeof(char*) * (*returnSize));
    int index1 = 2 * n - 1, index2 = 2 * n;
    for (int i = 0; i < *returnSize; ++i) {
        out[i] = (char*)malloc(sizeof(char) * (index2+1));
        out[i][index1] = '1'; // number of '('
        out[i][index2] = '1'; // number of '(' - number of ')'
    }

    out[0][0] = '(';
    *returnSize = 1;
    char char_n = n + '0';
    for (int i = 1; i < index1; ++i) {
        int count = *returnSize;
        for (int j = 0; j < count; ++j) {
            // number of '(' < n && #'(' - #')' >0
            if (out[j][index1] < char_n && out[j][index2] > '0') {
                strncpy(out[*returnSize], out[j], index2+1);
                out[*returnSize][i] = '(';
                out[*returnSize][index1]++;
                out[*returnSize][index2]++;
                (*returnSize)++;
                out[j][i] = ')';
                out[j][index2]--;
            }
            else if (out[j][index1] < char_n) {
                out[j][i] = '(';
                out[j][index1]++;
                out[j][index2]++;
            }
            else {
                out[j][i] = ')';
                out[j][index2]--;
            }
        }
    }
    // i = 2 * n - 1
    for (int j = 0; j < *returnSize; ++j) {
        out[j][index1] = ')';
        out[j][index2] = '\0';
    }
    return out;
}
