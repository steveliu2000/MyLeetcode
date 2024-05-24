int climbStairs(int n) {
    if (n <= 3) return n;
    // n >= 4
    int i=2, j=3, k, cn=3;
    while (cn != n) {
        k = i + j;
        i = j;
        j = k;
        ++cn;
    }
    return k;
}
