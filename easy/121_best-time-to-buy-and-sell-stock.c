int maxProfit(int* prices, int pricesSize) {
    int MaxProfit = 0, Profit = 0, buy = prices[0];
    for (int i = 1; i<pricesSize; ++i) {
        if (prices[i] > buy) {
            Profit = prices[i] - buy;
            MaxProfit = (MaxProfit > Profit)? MaxProfit : Profit;
        }
        else buy = prices[i];
    }
    return MaxProfit;
}
