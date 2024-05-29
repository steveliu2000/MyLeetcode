int reverse(int x){
    int output = 0;
    int max = INT_MAX /10, min = INT_MIN /10;
    while (x) {
        // −2,147,483,648 (−2^31) <= int<= 2,147,483,647 (2^31 − 1)
        // if(output>=214748365||output<=-214748365)
        if(output > max || output < min)
            return 0;
        output = output*10 + x % 10;
        x /= 10;
    }
    return output;
}
