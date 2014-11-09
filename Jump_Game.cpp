//We can do it with DP: O(n*n) -> TLE
class Solution {
public:
    bool canJump(int A[], int n) {
        bool reach[50000];

        for (int i = 0; i < 50000; i++)
            reach[i] = false;

        reach[0] = true;
        for (int i = 0; i < n; i++)
            for (int j = i; j <= i+A[i]; j++)
                reach[j] = true;

        if (reach[n-1])
            return true;

        return false;
    }
};

//Or just simulate the jumping, and care about A[i] == 0 only.
//Pay attention to special cases: empty input
//Input:    [0]
//Output:   false
//Expected: true

class Solution {
public:
    bool canJump(int A[], int n) {
        int max = 0;
        int now = 0;

        while (now < n-1)
        {
            if (max >= n-1 || now >= n-1 )
                return true;

            if (A[now] == 0)
                if (max == now)
                    return false;

            max = max > now + A[now] ? max : now+A[now];
            now++;
        }
        return true;
    }
};

