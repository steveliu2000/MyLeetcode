void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int temp[matrixSize * matrixSize], k = 0;
    for (int j = 0; j < matrixSize; ++j)
        for (int i = matrixSize-1; i >= 0; --i, ++k)
            temp[k] = matrix[i][j];
    k = 0;
    for (int i = 0; i < matrixSize; ++i)
        for (int j = 0; j < matrixSize; ++j, ++k)
            matrix[i][j] = temp[k];
}
