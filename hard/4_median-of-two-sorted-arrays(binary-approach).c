double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Binary Search (https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/4070500/99-journey-from-brute-force-to-most-optimized-three-approaches-easy-to-understand/)
    // Ensure nums1 is the smaller array for implicity
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    int n = nums1Size + nums2Size;
    // If merge is sorted concatenation of nums1 and nums2
    // median = merge[target] or (merge[target] + merge[target]) / 2
    int target = (n - 1) / 2;
    
    int low = 0, high = nums1Size;
    int l1, l2, r1, r2;
    while (low <= high) {
        // Calculate mid index for nums1
        int mid1 = (low + high) / 2;
        // Calculate mid index for nums2
        int mid2 = target + 1 - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        l1 = (mid1-1 >= 0)? nums1[mid1-1] : INT_MIN;
        l2 = (mid2-1 >= 0)? nums2[mid2-1] : INT_MIN;
        r1 = (mid1 < nums1Size)? nums1[mid1] : INT_MAX;
        r2 = (mid2 < nums2Size)? nums2[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            // The partition is correct, we found the median
            if (n % 2 == 1)
                return (l1 > l2)? l1 : l2;
            else {
                // (max(l1, l2) + min(r1, r2))) / 2.0;
                int l = (l1 > l2)? l1 : l2; // max(l1, l2)
                int r = (r1 < r2)? r1 : r2; //min(r1, r2)
                return (double)(l + r) / 2.0;
            }
        }
        else if (l1 > r2) {
            // Move towards the left side of nums1
            high = mid1 - 1;
            }
        else {
            // Move towards the right side of nums1
            low = mid1 + 1;
        }  
    }
    return 0; // If the code reaches here, the input arrays were not sorted.
}
