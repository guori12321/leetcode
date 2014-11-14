class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans0, ans1;

        ans0.push_back(1);

        for (int i = 0; i < rowIndex; i++)
        {
            vector<int> t;
            ans1 = t;
            ans1.push_back(1);
            for (int j = 1; j < ans0.size(); j++)
            {
                ans1.push_back(ans0[j] + ans0[j-1]);
            }
            ans1.push_back(1);
            ans0 = ans1;
        }

        return ans0;
    }
};

