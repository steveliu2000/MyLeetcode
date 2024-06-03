void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2, j, temp;
    // 从后向前找到第一个 nums[i] < nums[i + 1]
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }
    if (i != -1) {
        j = numsSize - 1;
        while (j > i && nums[j] <= nums[i]) {
            --j;
        }
        // swap nums[i] and nums[min_index]
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    // reverse nums[i + 1]~nums[numsSize - 1]
    i = i + 1;
    j = numsSize - 1;
    while (i < j) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        ++i;
        --j;
    }
}
