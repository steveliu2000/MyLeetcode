/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = 1;
    for (int i = 2; i <= numsSize; ++i)
        size *= i;
    int** out = malloc(size * sizeof(int*));
    *returnColumnSizes = malloc(size * sizeof(int));
    
    out[0] = malloc(numsSize * sizeof(int));
    memcpy(out[0], nums, numsSize*sizeof(int));
    qsort(out[0], numsSize, sizeof(int), cmp);
    (*returnColumnSizes)[0] = numsSize;
    *returnSize = 1;

    // 31_next-permutation.c
    while (true) {
        int i = numsSize - 2, j;
        int* last = out[(*returnSize)-1];
        // 从后向前找到第一个 nums[i] < nums[i + 1]
        while (i >= 0 && last[i] >= last[i + 1]) {
            --i;
        }
        if (i == -1) break;
        j = numsSize - 1;
        while (j > i && last[j] <= last[i]) {
            --j;
        }
        out[*returnSize] = malloc(numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        memcpy(out[*returnSize], last, i*sizeof(int));
        // swap nums[i] and nums[min_index]
        out[*returnSize][i] = last[j];
        out[*returnSize][j] = last[i];
    
        // reverse nums[i + 1]~nums[numsSize - 1]
        int sum = i + numsSize;
        for (int k = i + 1; k < numsSize; ++k)
            out[*returnSize][k] = last[sum - k];
        out[*returnSize][sum - j] = last[i];
        (*returnSize)++;
    }
    return out;
}
