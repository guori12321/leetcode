class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> f(n, 0);

        if (n == 0)
            return 0;

        f[0] = A[0];
        //We can't init ans = -99999, otherwise when n = 1, ans will still be -99999
        int ans = f[0];

        for (int i = 1; i < n; i++)
        {
            f[i] = max(A[i], f[i-1] + A[i]);
            ans = max(ans, f[i]);
        }

        return ans;
    }
};
