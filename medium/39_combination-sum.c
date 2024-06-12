/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
}

void cSHelper(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int layer, int** out) {
    int rS0;
    for (int i = 0; i < candidatesSize; ++i) {
        if (target > candidates[i]) {
            rS0 = *returnSize;
            cSHelper(&(candidates[i]), candidatesSize - i, target - candidates[i], returnSize, returnColumnSizes, layer + 1, out);
            for (int j = rS0; j < *returnSize; ++j)
                out[j][layer] = candidates[i];
        }
        else if (target == candidates[i]) {
            out[*returnSize] = malloc((layer + 1) * sizeof(int));
            out[*returnSize][layer] = target;
            (*returnColumnSizes)[*returnSize] = layer + 1;
            ++(*returnSize);
            break;
        }
        else break;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    *returnSize = 0;
    if (target < candidates[0]) return NULL;
    int** out = malloc(150 * sizeof(int*)), **ptr;
    *returnColumnSizes = malloc(150 * sizeof(int));
    cSHelper(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, out);
    return out;
}
