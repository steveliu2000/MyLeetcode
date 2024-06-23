/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 1;
    for (int i = 2; i <= numsSize; ++i)
        (*returnSize) *= i;
    int** out = malloc(*returnSize * sizeof(int*));
    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    
    out[0] = malloc(numsSize * sizeof(int));
    out[0][0] = nums[0];
    (*returnColumnSizes)[0] = numsSize;
    int size = 1;
    for (int i = 1; i < numsSize; ++i) {
        for (int j = 0; j < size; ++j) {
            out[j][i] = nums[i];
            for (int k = 1; k <= i; ++k) {
                int idx = j + k * size;
                out[idx] = malloc(numsSize * sizeof(int));
                (*returnColumnSizes)[idx] = numsSize;
                memcpy(out[idx], out[j], i*sizeof(int));
                out[idx][i] = out[j][i-k];
                out[idx][i-k] = nums[i];
            }
        }
        size *= i+1;
    }
    return out;
}
