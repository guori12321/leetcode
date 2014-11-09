//科学计数法: Scientific Notation
//Pay attention that the reversed result may overflow, however, in this case we don't handle that.

class Solution {
public:
    int getDigit(int x, int k)
    {
        return int(x % int(pow(10, k+1)) / int(pow(10, k)));
    }
    int reverse(int x) {
        unsigned int r = 0;
        bool flag = x < 0 ? false : true;
        x = abs(x);

        int n = trunc(log10(x)) + 1;

        for (int i = 0; i < n; i++)
        {
            int t = getDigit(x, i);
            r += int(pow(10, n-i-1))*t;
        }

        if (flag)
            return r;
        else
            return -r;
    }
};
