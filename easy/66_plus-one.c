/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // from right to left, find the first digit not 9.
    int i = digitsSize - 1, j;
    while (i >= 0 && digits[i] == 9) --i; //check i >= 0 first, if i < 0, digits[i] will overflow.

    int* output;
    if (i >= 0) {
        *returnSize = digitsSize;
        output = (int*)malloc(sizeof(int) * (*returnSize));
        for (j = 0; j < i; ++j) output[j] = digits[j];
        output[i] = digits[i] + 1;
        for (j = i+1; j < *returnSize; ++j) output[j] = 0;
    }
    //i<0 => 999...9
    else { 
        *returnSize = digitsSize + 1;
        output = (int*)malloc(sizeof(int) * (*returnSize));
        output[0] = 1;
        for (j = 1; j < *returnSize; ++j) output[j] = 0;
    }
    return output;
}
