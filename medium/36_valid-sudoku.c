bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int i, j;
    bool digit[9];
    // check row
    for (i = 0; i < 9; ++i) {
        memset(digit, false, 9);
        for (j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                if (digit[board[i][j] - '1'] == true)
                    return false;
                else digit[board[i][j] - '1'] = true;
            }
        }
    }
    // check column
    for (j = 0; j < 9; ++j) {
        memset(digit, false, 9);
        for (i = 0; i < 9; ++i) {
            if (board[i][j] != '.') {
                if (digit[board[i][j] - '1'] == true)
                    return false;
                else digit[board[i][j] - '1'] = true;
            }
        }
    }
    // check sub-boxes
    for (i = 0; i < 9; i+=3) {
        for (j = 0; j < 9; ++j) {
            if (j % 3 == 0) memset(digit, false, 9);
            if (board[i][j] != '.') {
                if (digit[board[i][j] - '1'] == true)
                    return false;
                else digit[board[i][j] - '1'] = true;
            }
            if (board[i+1][j] != '.') {
                if (digit[board[i+1][j] - '1'] == true)
                    return false;
                else digit[board[i+1][j] - '1'] = true;
            }
            if (board[i+2][j] != '.') {
                if (digit[board[i+2][j] - '1'] == true)
                    return false;
                else digit[board[i+2][j] - '1'] = true;
            }
        }
    }

    return true;
}
