int myAtoi(char* s) {
    while (*s == ' ')
        ++s;
    int neg = 0;
    if (*s == '-') {
        neg = 1;
        ++s;
    }
    else if (*s == '+') ++s;
    /*
    int ans = 0, max = INT_MAX /10, min = INT_MIN /10;
    while (isdigit(*s)) {
        // INT_MAX = 2,147,483,647
        if(ans > max || (ans == max && (*s-'0')>7)) return INT_MAX;
        // INT_MIN = −2,147,483,648
        if(ans < min || (ans == min && (*s-'0')>8)) return INT_MIN;

        if (neg) ans = ans * 10 - (*s-'0');
        else ans = ans * 10 + (*s-'0');
        ++s;
    }
    */
    long long ans = 0;
    while (isdigit(*s)) {
        if (neg) ans = ans * 10 - (*s-'0');
        else ans = ans * 10 + (*s-'0');
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        ++s;
    }
    return ans;
}
