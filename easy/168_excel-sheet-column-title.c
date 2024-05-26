char* convertToTitle(int columnNumber) {
    
    char* output = malloc(sizeof(char));
    output[0] = '\0';
    int len = 1, i;
    //if (columnNumber == 0) return "A";
    while (columnNumber > 0) {
        --columnNumber;
        ++len;
        output = realloc(output, len);
        for (i = len-1; i>0; --i)
            output[i] = output[i-1];

        output[0] = 65 + columnNumber % 26; //ASCII of 'A' = 65
        columnNumber /= 26;
    }
    return output;
}
