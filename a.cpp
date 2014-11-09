class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 10)
                return false;
            int len = log10(x) + 1;
            for (int i = 0; i <= (len / 2 ); i++)
                if ( getDigit(x, i) != getDigit(x, len-i+1) )
                {
                    return false;
                }
            return true;
    }
};



