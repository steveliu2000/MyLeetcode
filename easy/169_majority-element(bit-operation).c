int majorityElement(int* nums, int numsSize) {
    // look at each position and calculate the 
    // highest occuring frequency between 0 and 1.
    int ones[32] = {0};
    int zeros[32] = {0};
    int i, j;
    for (i = 0; i<numsSize; ++i) {
        for (j = 0; j<32; ++j) {
            //The j-th from right is 1.
            if (nums[i] & (UINT32_C(1) << j)) ++ones[j]; 
            //left shift of 1 by 31 places cannot be represented in type 'int'
            //The j-th from right is 0.
            else ++zeros[j];
        }
    }

    int output = 0;
    for (i = 0; i<32; ++i) {
        if (ones[i] > zeros[i])
            output |= (UINT32_C(1) << i);
    }
    return output;
}
