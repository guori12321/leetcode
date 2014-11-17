class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        string ans1;

        if (n == 1)
            return ans;

        for (int i = 0; i < n-1; i++)
        {
            ans1 = "";
            int start = 0;
            ans += "x";

            for (int j = 1; j < ans.len(); j++)
            {
                if (ans[j] != ans[j-1])
                {
                    //String can add a char directly. to_string is for int only.
//                    ans1 += to_string(j-start) + to_string(ans[j-1]);
                    ans1 += to_string(j-start) + ans[j-1];
                    start = j;
                }
            }
            ans = ans1;
        }
        return ans;
    }
};
