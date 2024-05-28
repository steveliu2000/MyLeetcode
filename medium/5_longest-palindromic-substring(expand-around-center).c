char* longestPalindrome(char* s) {
    // Expand Around Center
    int PalIndex = 0, PalSize = 1, n = strlen(s);
    int i, j, l;
    for (int mid = 1; mid < n; ++mid) {
        // Check for even length palindrome centered at mid-1 and mid
        i = mid - 1; j = mid;
        while (i >= 0) {
            if (s[i] != s[j]) break;
            else {
                l = j - i + 1;
                if (l > PalSize) {
                    PalSize = l;
                    PalIndex = i;
                }
                --i;
                ++j;
            }
        }
        // Check for odd length palindrome centered at mid
        i = mid - 1; j = mid + 1;
        while (i >= 0 && j < n) {
            if (s[i] != s[j]) break;
            else {
                l = j - i + 1;
                if (l > PalSize) {
                    PalSize = l;
                    PalIndex = i;
                }
                --i;
                ++j;
            }
        }
    }
    char *output = (char *)malloc(PalSize + 1);
    strncpy(output, s + PalIndex, PalSize);
    output[PalSize] = '\0';
    return output;
}
