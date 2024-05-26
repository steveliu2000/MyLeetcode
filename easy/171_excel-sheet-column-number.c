int titleToNumber(char* columnTitle) {
    int output = 0;
    while (*columnTitle != '\0') {
        output *= 26;
        output += *columnTitle - 64;
        columnTitle += 1;
    }
    return output;
}
