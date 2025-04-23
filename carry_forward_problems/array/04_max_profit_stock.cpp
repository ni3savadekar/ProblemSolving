/*
4. Stock Buy and Sell for Max Profit
Problem: Maximize profit by buying and selling one stock.
Approach: Carry the min price so far.
*/

#include <vector>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
    int minPrice = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        profit = max(profit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return profit;
}