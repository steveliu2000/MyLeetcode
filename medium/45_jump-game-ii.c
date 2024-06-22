int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    int dp[numsSize];
    dp[0] = 0;
    for (int i = 1; i < numsSize; ++i)
        dp[i] = -1;
    int i = 0;
    while (dp[numsSize-1] == -1) {
        int min = dp[i] + 1;
        for (int j = 1; j <= nums[i]; ++j) {
            if (i+j < numsSize && (dp[i+j] > min || dp[i+j] == -1))
                dp[i+j] = min;
        }
        ++i;
    }
    return dp[numsSize-1];
}
