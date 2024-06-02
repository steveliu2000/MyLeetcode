/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char getletter(char num, int count) {
    if (num < '7' && count < 3) return (num - '2') * 3 + count + 'a';
    if (num == '7') return count + 'p';
    if (num == '8' && count < 3) return count + 't';
    if (num == '9') return count + 'w';
    return ' ';
}

char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }
    int len = 0, n79 = 0;
    while (digits[len] != '\0') {
        if (digits[len] == '7' || digits[len] == '9') n79++;
        len++;
    }

    *returnSize = pow(3, len-n79) * pow(4, n79);
    char** out = (char**)malloc(sizeof(char*) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i) {
        out[i] = (char*)malloc(sizeof(char) * (len+1));
        out[i][len] = '\0';
    }

    int amount = 1, j, mul;
    char num, letter[4];
    for (int i = 0; i < len; ++i) {
        num = digits[i];
        for (j = 0; j < 4; ++j) letter[j] = getletter(num, j); 
        if (letter[3] == ' ') {
            mul = 3;
            for (j = 0; j < amount; ++j) {
                strncpy(out[j+amount], out[j], i);
                out[j+amount][i] = letter[1];
                strncpy(out[j+amount+amount], out[j], i);
                out[j+amount+amount][i] = letter[2];
                out[j][i] = letter[0];
            }
        }
        else {
            mul = 4;
            for (j = 0; j < amount; ++j) {
                strncpy(out[j+amount], out[j], i);
                out[j+amount][i] = letter[1];
                strncpy(out[j+amount+amount], out[j], i);
                out[j+amount+amount][i] = letter[2];
                strncpy(out[j+amount*3], out[j], i);
                out[j+amount*3][i] = letter[3];
                out[j][i] = letter[0];
            }
        }
        amount *= mul;
    }
    return out;
}
