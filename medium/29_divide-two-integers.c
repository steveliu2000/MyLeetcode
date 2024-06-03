int divide(int dividend, int divisor) {
    int neg = (dividend ^ divisor) < 0;
    unsigned int quotient = 0;
    if (divisor < 0) {
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;
            else return 0;
        }
        else divisor = - divisor;
    }
    if (dividend < 0) {
        if (dividend == INT_MIN) {
            // dividend = 0 - (dividend + divisor)
            dividend = 0 - divisor - dividend;
            quotient = 1; 
        }
        else dividend = - dividend;
    }
    int i = 1;
    while ((dividend >> i) >= divisor) ++i; // divisor << i may overflow
    i--;
    
    while (i >= 0) {
        if (dividend >= (divisor << i)) {
            quotient += 1 << i;
            dividend -= divisor << i;
        }
        --i;
    }
    if (quotient > INT_MAX && neg == 0) return INT_MAX;
    if (neg) return -quotient;
    else return quotient;
}
