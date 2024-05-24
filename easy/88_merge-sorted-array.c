void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (n == 0) return;
    int i = m-1, j = n-1, k = nums1Size-1;
    while (i>=0 && j>=0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            --i;
        }
        else {
            nums1[k] = nums2[j];
            --j;
        }
        --k;
    }
    //nums2 left
    while(j>=0) {
        nums1[k] = nums2[j];
        --j;
        --k;
    }
}
