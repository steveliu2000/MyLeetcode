int lengthOfLastWord(char* s) {
    int l = 0;
    while (*s != '\0') {
        if (*s != ' ')
            ++l;
        else {
            char next = *(s+1);
            if (next != ' ' && next != '\0')
                l = 0;
        }
        ++s;
    }
    return l;
}
