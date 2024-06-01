/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    *returnSize = 0;
    int maxReturnSize = numsSize;
    int **out = (int**)malloc(sizeof(int*) * maxReturnSize);

    for (int i = 0; i < numsSize - 2; i++) {
        if (i == 0 || nums[i] != nums[i-1]) {
            int l = i + 1; // left
            int r = numsSize - 1; // right
            int sum = -nums[i];
            while (l < r) {
                if (nums[l] + nums[r] < sum) {
                    l++;
                } else if (nums[l] + nums[r] > sum) {
                    r--;
                } else { // nums[i] + nums[l] + nums[r] == 0
                    if (*returnSize == maxReturnSize) {
                        maxReturnSize += 10;
                        out = (int**)realloc(out, sizeof(int*) * maxReturnSize);
                    }
                    out[(*returnSize)] = (int*) malloc(sizeof(int) * 3);
                    out[(*returnSize)][0] = nums[i];
                    out[(*returnSize)][1] = nums[l];
                    out[(*returnSize)][2] = nums[r];
                    (*returnSize)++;
                    l++;
                    while (l < r && nums[l] == nums[l-1])
                        l++;
                }
            }
        }
    }
    
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return out;
}
