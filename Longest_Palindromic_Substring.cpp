//DP
class Solution {
public:
    string longestPalindrome(string s) {

        //the length can be 1000, so we need to claim f[1001][1000]
        bool f[1001][1000];
        int n = s.length();
        //incase of s is only one char
        int len = 1, left = 0;

        for (int i = 0; i < 1000; i++)
        {
            f[0][i] = true;
            f[1][i] = true;
        }

        //i is length
        for (int i = 2; i < n+1; i++)
        {
            //j is the start point
            for (int j = 0; j < n-i+1; j++)
            {
                if (s[j] == s[j+i-1] )
                {
                    //Update len only when f[i][j] is true
                    f[i][j] = f[i-2][j+1];
                    if (i > len && f[i][j])
                    {
                        len = i;
                        left = j;
                    }
                }
                else
                    f[i][j] = false;
            }
        }

        return s.substr(left, len);
    }
};

//Brute-force: TLE
//Note that the length of the palindromic string may be odd or even.
class Solution {
public:
    bool isPal(string s)
    {
        int n = s.length();

        for (int i = 0; i < n/2; i++)
            if (s[i] != s[n-1-i])
                return false;
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int len = 0, left = 0;

        for (int i = n; i >0; i--)
        //i is length
        {
            for (int j = 0; j < n-i+1; j++ )
            //j is the start point
            {
                if ( isPal( s.substr(j, i) ))
                {
                    return s.substr(j,i);
                }
            }
        }

        return s.substr(0, n);
    }
};
