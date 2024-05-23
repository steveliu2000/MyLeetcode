int searchInsert(int* nums, int numsSize, int target) {
    int half = numsSize/2, middle = nums[half];
    if (target < nums[0]) return 0;
    if (target > nums[numsSize-1]) return numsSize;
    if (target == middle) return half;
    if (target > middle) return half + searchInsert(nums+half, numsSize - half, target);
    else return searchInsert(nums, half, target);
}
