#include <iostream>
using namespace std;
// Naive solution
int maxProfit(int prices[], int start, int end)
{
    if (end <= start)
    {
        return 0;
    }
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (prices[j] > prices[i])
            {
                int sub_profit = prices[j] - prices[i] +
                                 maxProfit(prices, start, i - 1) + // checking maxProfit on the left of i
                                 maxProfit(prices, j + 1, end);    // checking maxProfit on the right of j
                profit = max(profit, sub_profit);
            }
        }
    }
    return profit;
}
// Efficient solution --> find peak and bottom points (at peak sell them and at bottom buy the stock)
int maxProfit1(int prices[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += (prices[i] - prices[i - 1]);
        }
    }
    return profit;
}
int main(int argc, char const *argv[])
{
    int profit[] = {1, 5, 3, 8, 12};
    cout << maxProfit1(profit, 5);
    return 0;
}
