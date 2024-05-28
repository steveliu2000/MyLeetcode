char* longestPalindrome(char* s) {
    // Manacher's Algorithm
    // https://zh.wikipedia.org/zh-tw/%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2#%E9%A9%AC%E6%8B%89%E8%BD%A6%E7%AE%97%E6%B3%95
    int c = 0, r = 0, n0 = strlen(s);
    char new_s[2*n0+1];
    int i = 0, j = 0;
    while (j < n0) {
        new_s[i] = s[j];
        ++i;
        ++j;
        new_s[i] = '$';
        ++i;
    }
    new_s[2*n0] = '\0';
    int n = strlen(new_s);

    int P[n]; // P[i] = is the radius of the longest palindrome which center at i.
    P[0] = 0;
    int lc, lr, rb, mc;
    while (c < n) {
        // find the radius of the longest palindrome which center at c.
        while (c-(r+1) >= 0 && c+(r+1) < n && new_s[c+(r+1)] == new_s[c-(r+1)])
            r = r + 1;
        P[c] = r;

        lc = c;
        lr = r;
        // right bound
        rb = lc + lr;

        // cycle to right bound
        ++c;
        r = 0;
        while (c < rb) {
            // mc is the point symmetric to c with respect to lc."
            mc = lc - (c - lc);
            if (c + P[mc] < rb) P[c] = P[mc]; // case 1, skip
            else if (c + P[mc] > rb) P[c] = rb - c; // case 2, skip
            else {
                // case 3, can't skip
                r = rb - c;
                break;
            }
            ++c;
        }
    }
    int MaxRadius = 0, MaxCenter = 0;
    for (int i = 1; i < n; ++i)
        if (P[i] > MaxRadius) {
            MaxRadius = P[i];
            MaxCenter = i;
        }
    // output new_s[MaxCenter-MaxRadius, MaxCenter+MaxRadius]
    int l_i = (MaxCenter - MaxRadius + 1) / 2;
    int r_i = (MaxCenter + MaxRadius) / 2;
    char *output = (char *)malloc(sizeof(char) * (r_i - l_i + 2));
    strncpy(output, s + l_i, r_i - l_i + 1);
    output[r_i - l_i + 1] = '\0';
    return output;
}
