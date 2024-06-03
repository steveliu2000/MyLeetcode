int search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        if (nums[low] > nums[mid]) { // mid < pivot index k
            if (target < nums[mid] || target > nums[high]) high = mid - 1;
            // target > nums[mid]
            else low = mid+1;
        }
        else {
            if (target > nums[mid] || target < nums[low])
                low = mid + 1;
            else high = mid-1;
        }
    }
    return -1;
}
