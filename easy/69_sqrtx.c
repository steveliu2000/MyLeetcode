int mySqrt(int x) {
    int high = 46340 - 1, low = 0, mid; //sqrt(pow(2, 31) - 1) = 46340.95...
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((mid+1) * (mid+1) <= x) low = mid + 1;
        else  if (mid * mid > x) high = mid - 1;
        else return mid;
    }
    return low;
}
