/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex+1;
    int* output = malloc(sizeof(int) * (*returnSize));
    output[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        output[i] = 1;
        for (int j = i-1; j > 0; --j)
            output[j] += output[j-1];
    }
    return output;
}
