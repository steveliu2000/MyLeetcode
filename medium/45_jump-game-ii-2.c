int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;

    int jumps = 0; // To count the number of jumps.
    int currentEnd = 0; // To keep track of the end of the range for the current jump.
    int farthest = 0; // To keep track of the farthest we can reach with the current jump.

    for (int i = 0; i < numsSize - 1; ++i) {
        farthest = (i + nums[i] > farthest) ? i + nums[i] : farthest;

        if (i == currentEnd) { // When we reach the end of the current jump range,
            jumps++; // increment the jump count,
            currentEnd = farthest; // and update the current end to the farthest point reachable.
            if (currentEnd >= numsSize - 1) break; // If the current end reaches or exceeds the last index, break out of the loop.
        }
    }
    return jumps;
}
