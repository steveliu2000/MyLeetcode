int romanToInt(char* s) {
    int a = 0, n = strlen(s), i;
    for (i=0; i<n; i++){
        switch (s[i]) {
            case 'I':
            if (s[i+1] == 'V') {
                a += 4;
                i++;
            }
            else {
                if (s[i+1] == 'X') {
                a += 9;
                i++;
                }
                else a += 1;
            }
            break;

            case 'X':
            if (s[i+1] == 'L') {
                a += 40;
                i++;
            }
            else {
                if (s[i+1] == 'C') {
                a += 90;
                i++;
                }
                else a += 10;
            }
            break;

            case 'C':
            if (s[i+1] == 'D') {
                a += 400;
                i++;
            }
            else {
                if (s[i+1] == 'M') {
                a += 900;
                i++;
                }
                else a += 100;
            }
            break;

            case 'V':
            a += 5;
            break;

            case 'L':
            a += 50;
            break;

            case 'D':
            a += 500;
            break;

            case 'M':
            a += 1000;
            break;
        }
    }
    return a;
}
