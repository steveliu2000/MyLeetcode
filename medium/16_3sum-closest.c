int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int sum, diff0 = INT_MAX, diff1, diff2;

    for (int i = 0; i < numsSize - 2; ++i) {
        int l = i+1;
        int r = numsSize - 1;
        diff1 = nums[i] - target;
        while (l < r) {
            diff2 = diff1 + nums[l] + nums[r];
            if (diff0 > abs(diff2)) {
                diff0 = abs(diff2);
                sum = diff2 + target;
            }
            if (diff2 < 0) l++;
            else if (diff2 > 0) r--;
            else return target; // nums[i]+nums[l]+nums[r] = target
        }
    }
    return sum;
}
