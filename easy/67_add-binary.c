char* addBinary(char* a, char* b) {
    int i_a = strlen(a)-1, i_b = strlen(b)-1;
    int max_len = (i_a > i_b) ? i_a:i_b, i = max_len;
    int val1, val2, carry = 0, bit_sum;
    char* sum = malloc(max_len+3); //max(a.length, b.length) + 2('\0' and carry)
    sum[max_len+2] = '\0';
    sum[max_len+1] = '\0';
    while (i_a >=0 || i_b >=0) {
        if (i_a < 0) val1 = 0;
        else {
            val1 = (a[i_a] == '0') ? 0:1;
            --i_a;
        }
        if (i_b < 0) val2 = 0;
        else {
            val2 = (b[i_b] == '0') ? 0:1;
            --i_b;
        }
        // assume there will be no carry at most significant bit.
        bit_sum = val1 + val2 + carry;
        sum[i] = bit_sum % 2 +'0';// int to char
        carry = bit_sum > 1;
        --i;
    }

    // if there is carry at most significant bit, move every bit backward
    if (carry) {
        for (i = max_len; i>=0; --i) sum[i+1] = sum[i];
        sum[0] = '1';
    }
    return sum;
}
