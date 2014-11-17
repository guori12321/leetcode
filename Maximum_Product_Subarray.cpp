//As for product, we need to record both max and minimal product, for the minimal times a negative integer may be the maximal product
class Solution {
public:
    int maxProduct(int A[], int n) {

        if (n == 0)
            return 0;

        if (n == 1)
            return A[0];

        vector<int> f, g;

        for (int i = 0; i < n; i++)
        {
            f.push_back(1);
            g.push_back(1);
        }
        f[0] = A[0];
        g[0] = A[0];
        int ans = A[0];
        //Initial ans with A[0]. We will miss A[0] if we initial with INT_MIN

        for (int i = 1; i < n; i++)
        {
            f[i] = max(A[i], max(f[i-1]*A[i], g[i-1]*A[i]) );
            g[i] = min(A[i], min(g[i-1]*A[i], f[i-1]*A[i]) );
            ans = max(ans, f[i]);
        }

        return ans;
    }
};
