bool isPalindrome(int x) {
    // 負數必非palindrome
    if (x<0) return false;
    else{
        // -2^31 <= x <= 2^31 - 1 < 10^10(做多10位數)
        int digit[10], n=0;
        while (x>=10){
            digit[n] = x%10;
            x = x/10;
            n++;
        }
        digit[n] = x; //x化為10進位有n+1位

        int i=0;
        while (i < n){
            if (digit[i] != digit[n]) return false;
            i++;
            n--;
        }
        return true;
    }
}
