struct intPair{
    int x;
    int order;
};

int compare(const void *a, const void *b){
      struct intPair c = *(struct intPair *)a;
      struct intPair d = *(struct intPair *)b;
      return c.x-d.x;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j;
    
    // 動態分配內存給結構體數組
    struct intPair *arr = malloc(numsSize * sizeof(struct intPair));
    for (i = 0; i < numsSize; ++i) {
        arr[i].x = nums[i];
        arr[i].order = i;
    }

    // 使用 qsort 函數對結構體數組進行排序
    qsort(arr, numsSize, sizeof(arr[0]), compare);

    // 初始化兩個指針，用於查找兩個數字
    i = 0;
    j = numsSize - 1;

    // 使用雙指針法查找兩數之和
    while (i < j) {
        int sum = arr[i].x + arr[j].x;
        if (sum == target) {
            // 找到目標和
            int *output = malloc(2 * sizeof(int));
            output[0] = arr[i].order;
            output[1] = arr[j].order;
            *returnSize = 2;
            free(arr);
            return output;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    // 未找到目標和
    *returnSize = 0;
    free(arr);
    return NULL;
}
