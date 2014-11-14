//It's another obvious greedy algorithm.
//Don't think too complex.

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int n = prices.size();
        int minVal = INT_MAX;

        if (n <= 1)
            return 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }

        return ans;
    }
};
