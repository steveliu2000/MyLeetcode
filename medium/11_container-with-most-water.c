int maxArea(int* height, int heightSize) {
    int water, max = 0;
    int i = 0, j = heightSize - 1;
    while (i < j) {
        if (height[i] < height[j]) {
            water = height[i] * (j-i);
            ++i;
        }
        else {
            water = height[j] * (j-i);
            --j;
        }
        max = (water > max)? water : max;
    }
    return max;
}
