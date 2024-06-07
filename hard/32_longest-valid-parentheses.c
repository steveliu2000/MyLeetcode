int longestValidParentheses(char* s) {
    int i = 0, sL, j;
    int stack = 0, count = 0, longest = 0;
    // forward
    while (s[i] == ')') ++i;
    //while (s[j] == ')') ++j;
    while (s[i] != '\0') {
        if (s[i] == '(') {
            ++stack;
            ++count;
        }
        else {
            --stack;
            if (stack < 0) {
                longest = (longest > count)? longest : count;
                count = 0;
                stack = 0;
            }
            else ++count;
        }
        ++i;
    }
    sL = i;
    if (count <= longest) return longest;
    
    i = sL - 1;
    while (stack > 0) {
        if (s[i] == '(') --stack;
        else ++stack;
        --count;
        --i;
    }
    longest = (longest > count)? longest : count;
    
    // backward
    j = sL - 1;
    count = 0;
    while (j >= 0 && s[j] == '(') --j;
    while (j >= 0) {
        if (s[j] == ')') {
            ++stack;
            ++count;
        }
        else {
            --stack;
            if (stack < 0) {
                longest = (longest > count)? longest : count;
                count = 0;
                stack = 0;
            }
            else ++count;
        }
        --j;
    }
    j = 0;
    while (stack > 0) {
        if (s[j] == ')') --stack;
        else ++stack;
        --count;
        ++j;
    }
    longest = (longest > count)? longest : count;
    return longest;
}
