char RomanLetters(int val) {
    switch (val) {
        case 1: return 'I';
        case 5: return 'V';
        case 10: return 'X';
        case 50: return 'L';
        case 100: return 'C';
        case 500: return 'D';
        case 1000: return 'M';
        default: return ' ';
    }
}

char* intToRoman(int num) {
    char* out = malloc(16);
    int digit = 1000;
    int i, j = 0;
    while (num > 0) {
        i = num / digit;
        num %= digit;
        while (i > 0) {
            if (i % 5 == 4) { // i == 4 or i == 9
                out[j] = RomanLetters(1*digit);
                ++j;
                ++i;
            }
            if (i == 10) {
                out[j] = RomanLetters(10*digit);
                ++j;
                break;
            }
            if (i >= 5) { // i == 5~8
                out[j] = RomanLetters(5*digit);
                ++j;
                i -= 5;
            }
            else {
                out[j] = RomanLetters(1*digit);
                ++j;
                --i;
            }
        }
        digit /= 10;
    }
    out[j] = '\0';
    return out;
}
