//Note about input 0, and 1
//Note about pow(10, 3), rather than 10^3
//
class Solution {
public:
    int getDigit(int x, int k){
        return (int)(x % int(pow(10, k+1)) / int(pow(10,k)));
    };

    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int len = trunc(log10(x)) + 1;
        for (int i = 0; i <= (len / 2 ); i++)
            if ( getDigit(x, i) != getDigit(x, len-i-1) )
                return false;
        return true;
    }
};
