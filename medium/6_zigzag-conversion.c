char* convert(char* s, int numRows) {
    if (numRows == 1) return strdup(s); // If numRows is 1, return the string as is.
    
    int n = strlen(s), j = 0;
    char *output = (char *)malloc(sizeof(char) * (n + 1));
    // row0 = 0, 0+2*numRows-2, ...
    int m = 2*numRows-2;
    for (int row = 0; row < numRows; ++row) {
        int i = row;
        while (i < n) {
            output[j] = s[i];
            ++j;
            if (row == 0 || row == numRows - 1) i += m;
            else {
                i += m - 2 * row;
                if (i >= n) break;
                output[j] = s[i];
                ++j;
                i += 2 * row;
            }
        }
    }
    output[n] = '\0';
    return output;
}
