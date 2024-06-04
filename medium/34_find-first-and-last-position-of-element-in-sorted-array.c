/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans[1] = -1;
    * returnSize = 2;
    int low = 0, high = numsSize - 1, high2 = high, mid;
    // find starting position
    while (low <= high) {
        mid = (low + high) / 2;
        if (target > nums[mid]) low = mid + 1;
        else if (target < nums[mid]) high = mid - 1;
        else { // target == nums[mid]
            if (mid == 0 || nums[mid - 1] != target) {
                ans[0] = mid;
                low = mid;
                break;
            }
            else high = mid - 1;
        }
        if (high == numsSize -1 || nums[high + 1] != target) 
            high2 = high;
    }
    // find ending position
    if (ans[0] != -1) low = ans[0];
    while (low <= high2) {
        mid = (low + high2) / 2;
        if (target > nums[mid]) low = mid + 1;
        else if (target < nums[mid]) high2 = mid - 1;
        else {
            if (mid == numsSize -1 || nums[mid + 1] != target) {
                ans[1] = mid;
                break;
            }
            else low = mid + 1;
        }
    }
    return ans;       
}
