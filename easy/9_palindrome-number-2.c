bool isPalindrome(int x) {
    // 負數必非palindrome
    if (x<0) return false;
    else{
        long int x_inv = 0;
        long int s = x;
        while (s>0){
            x_inv = x_inv * 10 + s%10;
            s/=10;
        }
        if (x_inv == x) return 1;
        else return 0;
    }
}
