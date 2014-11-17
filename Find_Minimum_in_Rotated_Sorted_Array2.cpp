class Solution {
public:
    int DFS(int l , int r, vector<int> &num)
    {
        if (l > r || l >= num.size() || r < 0)
        {
            return INT_MAX;
        }

        while (r > l && num[r] == num[l])
            r--;

        if (num[l] < num[r])
            return num[l];

        int m = (l+r)/2;

        //3 conditions:
        //l < r, l == r, l > r

        if (l == r)
            return num[l];

        return min(DFS(l, m, num), DFS(m+1, r, num));
    }

    int findMin(vector<int> &num) {
        return DFS(0, num.size()-1, num);
    }
};
