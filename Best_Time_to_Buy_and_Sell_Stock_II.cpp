//You can only buy and sell one stock once. You don't need to consider how much money you need to spend, you can just buy one.
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            ans += prices[i] - prices[i-1] > 0 ? prices[i] - prices[i-1] : 0;
        }
        return ans;
    }
};
