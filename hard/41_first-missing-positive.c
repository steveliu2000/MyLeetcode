int firstMissingPositive(int* nums, int numsSize) {
    // https://leetcode.com/problems/first-missing-positive/solutions/4925916/c-solution-for-first-missing-positive-problem/
    // 1. Move all non-positive integers to the end of the array, leaving only positive integers at the beginning.
    int temp, nonPosIdx = numsSize - 1;
    while (nonPosIdx >= 0 && nums[nonPosIdx] <= 0) --nonPosIdx;
    for (int i = 0; i < nonPosIdx; ++i) {
        if (nums[i] <= 0) {
            temp = nums[i];
            nums[i] = nums[nonPosIdx];
            nums[nonPosIdx] = temp;
            while (nums[nonPosIdx] <= 0) --nonPosIdx;
        }
    }
    // 2. Mark the presence of positive integers by negating the corresponding index.
    int numIdx;
    for (int i = 0; i <= nonPosIdx; i++) {
        numIdx = abs(nums[i])-1;
        if (numIdx <= nonPosIdx && nums[numIdx] > 0) {
            nums[numIdx] *= -1;
        }
    }
    // 3. Find the first missing positive integer.
    for (int i = 0; i <= nonPosIdx; i++) {
        if (nums[i] > 0) {
            return i+1;
        }
    }

    return nonPosIdx+2;
}
