void fillIn(char** board, int i, int j, int digit, bool possible[9][9][9], int possible_count[9][9], int digit_possible_count[9][3][9], int* empty_count) {
    int k, l, m, n, digit2;
    int box, box_i, box_j, box_i2, box_j2;
    for (digit2 = 0; digit2 < 9; ++digit2) {
        if (possible[i][j][digit2]) {
            possible[i][j][digit2] = false;
            --possible_count[i][j];
            --digit_possible_count[digit2][0][i];
            --digit_possible_count[digit2][1][j];
            --digit_possible_count[digit2][2][i/3*3 + j/3];
        }
    }
    board[i][j] = '1' + digit;
    --(*empty_count);
    if (*empty_count == 0) return;

    // Update possibilities for the current row, column, and box
    for (k = 0; k < 9; ++k) {
        // row i
        if (possible[i][k][digit]) {
            possible[i][k][digit] = false;
            --possible_count[i][k];
            --digit_possible_count[digit][0][i];
            --digit_possible_count[digit][1][k];
            --digit_possible_count[digit][2][i/3*3 + k/3];
        }
        // column j
        if (possible[k][j][digit]) {
            possible[k][j][digit] = false;
            --possible_count[k][j];
            --digit_possible_count[digit][0][k];          
            --digit_possible_count[digit][1][j];
            --digit_possible_count[digit][2][k/3*3 + j/3];
        }
    }
    // box
    box = i/3*3 + j/3;
    box_i = (i / 3) * 3;
    box_j = (j / 3) * 3;
    for (k = box_i; k < box_i+3; ++k) {
        for (l = box_j; l < box_j+3; ++l) {
            if (possible[k][l][digit]) {
                possible[k][l][digit] = false;
                --possible_count[k][l];
                --digit_possible_count[digit][0][k];
                --digit_possible_count[digit][1][l];
                --digit_possible_count[digit][2][box];
            }
        }
    }
    // fillIn row, column
    for (k = 0; k < 9; ++k) {
        if (possible_count[i][k] == 1) {
            for (digit2 = 0; digit2 < 9; ++digit2)
                if (possible[i][k][digit2]) break;
            fillIn(board, i, k, digit2, possible, possible_count, digit_possible_count, empty_count);
            if (*empty_count == 0) return;
        }
        if (possible_count[k][j] == 1) {
            for (digit2 = 0; digit2 < 9; ++digit2)
                if (possible[k][j][digit2]) break;
            fillIn(board, k, j, digit2, possible, possible_count, digit_possible_count, empty_count);
            if (*empty_count == 0) return;
            }
    }
    // fillIn box
    for (k = box_i; k < box_i+3; ++k) {
        for (l = box_j; l < box_j+3; ++l) {
            if (possible_count[k][l] == 1) {
                for (digit2 = 0; digit2 < 9; ++digit2)
                    if (possible[k][l][digit2]) break;
                fillIn(board, k, l, digit2, possible, possible_count, digit_possible_count, empty_count);
                if (*empty_count == 0) return;
            }
        }
    }
    
    // fillIn digit_possible_count
    for (k = 0; k < 9; ++k) {
        if (digit_possible_count[digit][0][k] == 1) {
            for (j = 0; j < 9; ++j)
                if (possible[k][j][digit]) break;
            fillIn(board, k, j, digit, possible, possible_count, digit_possible_count, empty_count);
            if (*empty_count == 0) return;
        }
        if (digit_possible_count[digit][1][k] == 1) {
            for (i = 0; i < 9; ++i)
                if (possible[i][k][digit]) break;
            fillIn(board, i, k, digit, possible, possible_count, digit_possible_count, empty_count);
            if (*empty_count == 0) return;
        }
        if (digit_possible_count[digit][2][k] == 1) {
            box_i = (k / 3) * 3;
            box_j = (k % 3) * 3;
            for (l = box_i; l < box_i+3; ++l) {
                for (m = box_j; m < box_j+3; ++m)
                    if (possible[l][m][digit]) break;
                if (m < box_j + 3) break;
            }
            fillIn(board, l, m, digit, possible, possible_count, digit_possible_count, empty_count);
            if (*empty_count == 0) return;
        }
    }
}

void try_fillIn(char** board, int i, int j, int digit, bool possible[9][9][9], int possible_count[9][9], int digit_possible_count[9][3][9], int* empty_count) {
    fillIn(board, i, j, digit, possible, possible_count, digit_possible_count, empty_count);
    if (*empty_count == 0) return;
    
    // copy information for retrieve
    char* board2[9];
    bool possible2[9][9][9];
    int possible_count2[9][9];
    int digit_possible_count2[9][3][9];
    int empty_count2 = *empty_count;
    for (i = 0; i < 9; ++i) {
        board2[i] = (char*)malloc(9 * sizeof(char));
        for (j = 0; j < 9; ++j) {
            board2[i][j] = board[i][j];
            possible_count2[i][j] = possible_count[i][j];
            digit_possible_count2[i][0][j] = digit_possible_count[i][0][j];
            digit_possible_count2[i][1][j] = digit_possible_count[i][1][j];
            digit_possible_count2[i][2][j] = digit_possible_count[i][2][j];
            for (digit = 0; digit < 9; ++digit) {
                possible2[i][j][digit] = possible[i][j][digit];
            }
        }
    }
    
    int smallest_possible[3] = {9, 0, 0};// {count, i, j}
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (possible_count[i][j] < smallest_possible[0] && possible_count[i][j] != 0) {
                smallest_possible[0] = possible_count[i][j];
                smallest_possible[1] = i;
                smallest_possible[2] = j;
            }
            if (possible_count[i][j] <= 2 && possible_count[i][j] != 0) break;
        }
        if (j < 9) break;
    }
    if (smallest_possible[0] == 9) return; // all possible_count[i][j] = 0
    if (i >= 9) {
        i = smallest_possible[1];
        j = smallest_possible[2];
    }

        for (digit = 0; digit < 9; ++digit) {
        if (possible[i][j][digit]) {
        	try_fillIn(board, i, j, digit, possible, possible_count, digit_possible_count, empty_count);
            if (*empty_count == 0) return;
            // retrieve
            for (int i2 = 0; i2 < 9; ++i2) {
                for (int j2 = 0; j2 < 9; ++j2) {
                    board[i2][j2] = board2[i2][j2];
                    possible_count[i2][j2] = possible_count2[i2][j2];
                    digit_possible_count[i2][0][j2] = digit_possible_count2[i2][0][j2];
                    digit_possible_count[i2][1][j2] = digit_possible_count2[i2][1][j2];
                    digit_possible_count[i2][2][j2] = digit_possible_count2[i2][2][j2];
                    for (int digit2 = 0; digit2 < 9; ++digit2) {
                        possible[i2][j2][digit2] = possible2[i2][j2][digit2];
                    }
                }
            }
            *empty_count = empty_count2;
        }
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    int i, j, k, l, digit, digit2;
    int box, box_i, box_j;
    bool possible[9][9][9];
    memset(possible, true, 9 * 9 * 9);
    int possible_count[9][9];
    // possible count for [digit][row/col/box][row/col/box_index]
    int digit_possible_count[9][3][9];
    int empty_count = 0;

    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            possible_count[i][j] = 9;
            digit_possible_count[i][0][j] = 9;
            digit_possible_count[i][1][j] = 9;
            digit_possible_count[i][2][j] = 9;
        }
    }

    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                digit = board[i][j] - '1';
                for (digit2 = 0; digit2 < 9; ++digit2) {
                    if (possible[i][j][digit2]) {
                        possible[i][j][digit2] = false;
                        --possible_count[i][j];
                        --digit_possible_count[digit2][0][i];
                        --digit_possible_count[digit2][1][j];
                        --digit_possible_count[digit2][2][i/3*3 + j/3];
                    }
                }
                for (k = 0; k < 9; ++k) {
                    if (possible[i][k][digit]) {
	                    possible[i][k][digit] = false;
	                    --possible_count[i][k];
                        --digit_possible_count[digit][0][i];
                        --digit_possible_count[digit][1][k];
                        --digit_possible_count[digit][2][i/3*3 + k/3];
                	}
                	if (possible[k][j][digit]) {
	                    possible[k][j][digit] = false;
	                    --possible_count[k][j];
                        --digit_possible_count[digit][0][k];
                        --digit_possible_count[digit][1][j];
                        --digit_possible_count[digit][2][k/3*3 + j/3];
                	}
                }
                box = (i / 3) * 3 + j / 3;
                box_i = (i / 3) * 3;
			    box_j = (j / 3) * 3;
                for (k = box_i; k < box_i+3; ++k) {
                    for (l = box_j; l < box_j+3; ++l) {
                        if (possible[k][l][digit]) {
	                        possible[k][l][digit] = false;
	                        --possible_count[k][l];
	                        --digit_possible_count[digit][0][k];
                            --digit_possible_count[digit][1][l];
                            --digit_possible_count[digit][2][box];
                    	}
                    }
                }
            }
            else ++empty_count;
        }
    }
    
    
    // fillIn digit_possible_count
    for (digit = 0; digit < 9; ++digit) {
        for (k = 0; k < 9; ++k) {
            if (digit_possible_count[digit][0][k] == 1) {
                for (j = 0; j < 9; ++j)
                    if (possible[k][j][digit]) break;
                fillIn(board, k, j, digit, possible, possible_count, digit_possible_count, &empty_count);
                if (empty_count == 0) return;
            }
            if (digit_possible_count[digit][1][k] == 1) {
                for (i = 0; i < 9; ++i)
                    if (possible[i][k][digit]) break;
                fillIn(board, i, k, digit, possible, possible_count, digit_possible_count, &empty_count);
                if (empty_count == 0) return;
            }
            if (digit_possible_count[digit][2][k] == 1) {
                box_i = (k / 3) * 3;
                box_j = (k % 3) * 3;
                for (i = box_i; i < box_i+3; ++i) {
                    for (j = box_j; j < box_j+3; ++j)
                        if (possible[i][j][digit]) break;
                    if (j < box_j + 3) break;
                }
                fillIn(board, i, j, digit, possible, possible_count, digit_possible_count, &empty_count);
                if (empty_count == 0) return;
            }
        }
    }

    // copy information for retrieve
    char* board2[9];
    bool possible2[9][9][9];
    int possible_count2[9][9];
    int digit_possible_count2[9][3][9];
    int empty_count2 = empty_count;
    for (i = 0; i < 9; ++i) {
        board2[i] = (char*)malloc(9 * sizeof(char));
        for (j = 0; j < 9; ++j) {
            board2[i][j] = board[i][j];
            possible_count2[i][j] = possible_count[i][j];
            digit_possible_count2[i][0][j] = digit_possible_count[i][0][j];
            digit_possible_count2[i][1][j] = digit_possible_count[i][1][j];
            digit_possible_count2[i][2][j] = digit_possible_count[i][2][j];
            for (digit = 0; digit < 9; ++digit) {
                possible2[i][j][digit] = possible[i][j][digit];
            }
        }
    }
    
    int smallest_possible[3] = {9, 0, 0};// {count, i, j}
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (possible_count[i][j] < smallest_possible[0] && possible_count[i][j] != 0) {
                smallest_possible[0] = possible_count[i][j];
                smallest_possible[1] = i;
                smallest_possible[2] = j;
            }
            if (possible_count[i][j] <= 2 && possible_count[i][j] != 0) break;
        }
        if (j < 9) break;
    }
    if (i < 9) {
        i = smallest_possible[1];
        j = smallest_possible[2];
    }

    for (digit = 0; digit < 9; ++digit) {
        if (possible[i][j][digit]) {
        	try_fillIn(board, i, j, digit, possible, possible_count, digit_possible_count, &empty_count);
            if (empty_count == 0) return;
            // retrieve
            for (int i2 = 0; i2 < 9; ++i2) {
                for (int j2 = 0; j2 < 9; ++j2) {
                    board[i2][j2] = board2[i2][j2];
                    possible_count[i2][j2] = possible_count2[i2][j2];
                    digit_possible_count[i2][0][j2] = digit_possible_count2[i2][0][j2];
                    digit_possible_count[i2][1][j2] = digit_possible_count2[i2][1][j2];
                    digit_possible_count[i2][2][j2] = digit_possible_count2[i2][2][j2];
                    for (digit2 = 0; digit2 < 9; ++digit2) {
                        possible[i2][j2][digit2] = possible2[i2][j2][digit2];
                    }
                }
            }
            empty_count = empty_count2;
        }
    }

    /*
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            // fillIn possible_count
            if (possible_count[i][j] == 1) {
                for (digit = 0; digit < 9; ++digit)
                    if (possible[i][j][digit]) break;
                fillIn(board, i, j, digit, possible, possible_count, digit_possible_count, &empty_count);
                if (empty_count == 0) return;
            }
        }
    }
    */

    /*
    digit2 = 4;
    printf("digit_possible_count of %d:\n", digit2+1);
    for (int i = 0; i < 3; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < 9; ++j) {
            printf("%d ", digit_possible_count[digit2][i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    /*
    printf("possible_count\n");
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", possible_count[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

}
/*
int main(void) {
	// your code goes here
	char a[9][9] = {
        {'.', '.', '9', '7', '4', '8', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
        {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
        {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
        {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
        {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
        {'.', '.', '.', '2', '7', '5', '9', '.', '.'}
	};
	char* board[9];
	for (int i = 0; i < 9; ++i) {
		board[i] = (char*)malloc(9);
        for (int j = 0; j < 9; ++j) {
            board[i][j] = a[i][j];
        }
    }
    int boardColSize[9] = {9,9,9,9,9,9,9,9,9};
    solveSudoku(board, 9, boardColSize);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	return 0;
}
*/
