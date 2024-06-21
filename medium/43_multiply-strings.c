char* multiply(char* num1, char* num2) {
    if (*num1 == '0' || *num2 == '0') {
        char* out = malloc(2);
        out[0] = '0';
        out[1] = '\0';
        return out;
    }

    int l1 = strlen(num1), l2 = strlen(num2);
    int n1_l = l1 / 4, n2_l = l2 / 4;
    int n1_left = l1 % 4, n2_left = l2 % 4;
    int i, j;
    if (n1_left) {
        ++n1_l;
        i = 1;
    }
    else i = 0;
    int* n1 = calloc(n1_l, sizeof(int));
    for (j = 0; j < n1_left; ++j) n1[0] = n1[0] * 10 + (num1[j] - '0');
    for (; i < n1_l; ++i) {
        n1[i] = (num1[j] - '0')*1000 + (num1[j+1] - '0')*100 + (num1[j+2] - '0')*10 + (num1[j+3] - '0');
        j += 4;
    }
    if (n2_left)  {
        ++n2_l;
        i = 1;
    }
    else i = 0;
    int* n2 = calloc(n2_l, sizeof(int));
    for (j = 0; j < n2_left; ++j) n2[0] = n2[0] * 10 + (num2[j] - '0');
    for (; i < n2_l; ++i) {
        n2[i] = (num2[j] - '0')*1000 + (num2[j+1] - '0')*100 + (num2[j+2] - '0')*10 + (num2[j+3] - '0');
        j += 4;
    }
    
    int* ans = calloc(n1_l + n2_l - 1, sizeof(int));
    for (i = 0; i < n1_l; ++i) {
        for (j = 0; j < n2_l; ++j) {
            ans[i+j] += n1[i] * n2[j];
        }
    }
    for (i = n1_l + n2_l - 2; i >= 1; --i) {
        ans[i-1] += ans[i] / 10000;
        ans[i] %= 10000;
    }
    char* out = malloc(l1 + l2 + 1);
    i = 0;
    while (ans[0] > 0) {
        out[i] = ans[0] % 10 + '0';
        ++i;
        ans[0] /= 10;
    }
    int l = 0, r = i - 1;
    char temp;
    while (l < r) {
        temp = out[l];
        out[l] = out[r];
        out[r] = temp;
        ++l;
        --r;
    }
    for (j = 1; j < n1_l + n2_l - 1; ++j) {
        out[i] = ans[j] / 1000 + '0';
        out[i+1] = (ans[j] % 1000) / 100 + '0';
        out[i+2] = (ans[j] % 100) / 10 + '0';
        out[i+3] = (ans[j] % 10) + '0';
        i += 4;
    }
    out[i] = '\0';
    return out;
}
