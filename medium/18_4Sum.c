/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 0;
    int maxReturnSize = numsSize;
    int **out = (int**)malloc(sizeof(int*) * maxReturnSize);
    
    for (int i = 0; i < numsSize - 3; ++i) {
        if (i == 0 || nums[i] != nums[i-1]) {
            for (int j = i + 1; j < numsSize - 2; ++j) {
                if (j == i + 1 || nums[j] != nums[j-1]) {
                    int l = j + 1; // left
                    int r = numsSize - 1; // right
                    long long sum = (long long)target - nums[i] - nums[j];
                    while (l < r) {
                        if (nums[l] + nums[r] < sum) {
                            l++;
                        } else if (nums[l] + nums[r] > sum) {
                            r--;
                        } else {
                            if (*returnSize == maxReturnSize) {
                                maxReturnSize += 10;
                                out = (int**)realloc(out, sizeof(int*) * maxReturnSize);
                            }
                            out[(*returnSize)] = (int*) malloc(sizeof(int) * 4);
                            out[(*returnSize)][0] = nums[i];
                            out[(*returnSize)][1] = nums[j];
                            out[(*returnSize)][2] = nums[l];
                            out[(*returnSize)][3] = nums[r];
                            (*returnSize)++;
                            do {
                                l++;
                            } while (l < r && nums[l] == nums[l-1]);
                        }
                    }
                }
            }
        }
    }
    
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 4;
    }
    return out;
}
