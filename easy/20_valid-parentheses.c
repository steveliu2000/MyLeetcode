bool isValid(char* s) {
    int i=0, n=0;
    char current = s[0];
    char stack[10000];
    while (current != '\0'){
        switch (current){
            case '(': case '[': case '{':
            stack[n] = current;
            n++;
            break;

            case ')':
            if (n>0 && stack[n-1] == '(') {
                n--;
                break;
            }
            else return false;
            case ']':
            if (n>0 && stack[n-1] == '[') {
                n--;
                break;
            }
            else return false;
            case '}':
            if (n>0 && stack[n-1] == '{') {
                n--;
                break;
            }
            else return false;
            default: break;
        }
        i++;
        current = s[i];
    }
    if (n==0) return true;
    else return false;
}
