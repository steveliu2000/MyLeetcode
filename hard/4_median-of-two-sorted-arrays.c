double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int target = (nums1Size + nums2Size - 1) / 2;
    int i = 0, j = 0;
    while (target > 0) {
        if (j >= nums2Size || (i < nums1Size && nums1[i] < nums2[j])) ++i;
        else ++j;
        --target;
    }
    int m1, m2;
    if (j >= nums2Size || (i < nums1Size && nums1[i] < nums2[j])) {
        m1 = nums1[i];
        ++i;
    }
    else {
        m1 = nums2[j];
        ++j;
    }

    if ((nums1Size + nums2Size) % 2 == 0) {
        m2 = (j >= nums2Size || (i < nums1Size && nums1[i] < nums2[j]))? nums1[i] : nums2[j];
        return (double)(m1 + m2) / 2;
    }
    else return (double) m1;
}
