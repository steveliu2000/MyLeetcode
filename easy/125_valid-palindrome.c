bool isPalindrome(char* s) {
    char* ptr1 = s, * ptr2 = s + strlen(s) - 1;
    while (ptr1 < ptr2) {
        while (!isalnum(*ptr2)) {
            --ptr2;
            if (ptr2 < s) return true; //all not alphanumeric
            }
        while (!isalnum(*ptr1)) ++ptr1;
        while (!isalnum(*ptr2)) --ptr2;
        if (tolower(*ptr1) == tolower(*ptr2)) {
            ++ptr1;
            --ptr2;
        }
        else return false;
    }
    return true;
}
