bool isMatch(char* s, char* p) {
    int m = strlen(s), n = strlen(p);
    bool dp[m+1][n+1]; // dp[i][j] = isMatch(s[0~i-1], p[0~j-1])
    // dp[i][0] = false;
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for(int i=0; i <= m; i++) { // dp[0][j] may be true;
        for(int j=1; j <= n; j++) {
            if(p[j-1] == '*') {
                dp[i][j] = dp[i][j-1] // "*" is not used
                || (i > 0 && dp[i-1][j]);
            }
            else {
                dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
            }
        }
    }
    return dp[m][n];
}
