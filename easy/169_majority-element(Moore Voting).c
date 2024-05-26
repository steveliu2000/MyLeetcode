int majorityElement(int* nums, int numsSize) {
    // Moore Voting Algorithm
    int candidate, count = 0;
    for (int i = 0; i<numsSize; ++i) {
        if (count != 0) {
            if (nums[i] == candidate) ++count;
            else  --count;
        }
        else {
            candidate = nums[i];
            ++count;
        }
    }
    return candidate;
}
