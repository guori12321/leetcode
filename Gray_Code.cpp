//Reading the question: n is the number of bits, not number itself

class Solution {
public:
    vector<int> grayCode(int n) {
        //C++ 98 does not support round()
        vector<int> ans;

        //I think when n = 0, we should give an empty result of 0 bits. However, leetcode asks for [0].
        if (n == 0)
        {
            ans.push_back(0);
            return ans;
        }

        ans.push_back(0);
        ans.push_back(1);

        for (int i = 1; i < n; i++)
        {
            int k = ans.size();
            for (int j = 0; j < k; j++)
            {
                int t = ans[k - 1 - j];
                t |= 1 << i;
                ans.push_back( t );
            }
        }

        return ans;
    }
};
