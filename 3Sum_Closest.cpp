class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        int ans = 0;
        int delta = INT_MAX;

        if (n == 1)
            return num[0];
        if (n == 2)
            return num[0] + num[1];
        if (n == 3)
            return num[0] + num[1] + num[2];

//        sort(num.begin(), num.end());
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (num[i] > num[j])
                {
                    int t = num[i];
                    num[i] = num[j];
                    num[j] = t;
                }

        for (int i = 0; i < n - 2; i++)
        {
            //We cannot initial delta here. delta should be a global variable like ans
            int j = i+1, k = n-1;

            while (j < k)
            {
                int tot = num[i] + num[j] + num[k];
                if (delta > abs(tot-target))
                {
                    delta = abs(tot-target);
                    ans = tot;
                }
                if (tot > target)
                    k--;
                else
                    if (tot < target)
                        j++;
                    else
                        return tot;
            }
        }

        return ans;
    }
};
