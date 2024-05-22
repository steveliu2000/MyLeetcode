int val(char s) {
    switch (s) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    int a = 0, n = strlen(s);
    for (int i=0; i<n; i++){
        // i < n - 1防止越界錯誤
        if (i < n - 1 && val(s[i]) < val(s[i+1])) a-=val(s[i]);
        else a+=val(s[i]);
    }
    return a;
}
