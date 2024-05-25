/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; ++i)
        (*returnColumnSizes)[i] = i + 1;
    
    int** output = malloc(sizeof(int*) * numRows);
    for (int i = 0; i < numRows; ++i) {
        output[i] = malloc(sizeof(int) * (i+1));
        for (int j = 0; j <= i; ++j)
            if (j == 0 || j == i) output[i][j] = 1;
            else output[i][j] = output[i-1][j-1] + output[i-1][j];
    }
    return output;
}
