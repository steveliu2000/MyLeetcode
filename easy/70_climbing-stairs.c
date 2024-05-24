int climbStairs(int n) {
    if (n <= 3) return n;
    int arr[n-2];
    //arr[i] = distinct ways to climb i+2 stairs.
    arr[0] = 2; arr[1] = 3;
    for (int i = 2; i < n-2; ++i)
        arr[i] = arr[i - 1] + arr[i - 2];
    return arr[n - 3] + arr[n - 4];
}
